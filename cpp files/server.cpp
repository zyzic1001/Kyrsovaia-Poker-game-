#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include "windows.h"

#pragma warning(disable: 4996)



struct clientInfo {
    char nickname[15];
    char password[15];
    int money;// < 9999
    int winCount;
    int loseCount;
};

struct gamers {
    char nickname[15];
    int money;
    int winCount;
    int loseCount;
    SOCKET Connection;
};

SOCKET connections[6];
int counter = 0;
int anotherCounter = 0;
clientInfo masOfClients[20];
int amountOfClients = 0;
bool endOfWork = false; //проверяем конец работы всей программы
gamers masOfGamers[6] = {};
int amountOfGamers = 0;
gamers newGamers[6] = {};
int amountOfNewGamers = 0;
bool serverIsWorkingWithNewGamers = false;
bool gameIsWorkingWithNewGamers = false;
bool notNow = true;
bool gameIsGoing = false;
int readyCount = 0;
int skolkoIgrokov = 0;


void getClientInfoFromFile() {
    std::string line;
    std::ifstream in("C:\\Users\\user\\source\\repos\\Курсовая сервер\\Курсовая сервер\\clientData.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            for (int i = 0; i < 15; i++) {
                masOfClients[amountOfClients].nickname[i] = line[i];
            }
            for (int i = 15; i < 30; i++) {
                masOfClients[amountOfClients].password[i] = line[i];
            }
            int mon = 0;
            int b = 1;
            for (int i = 35; i > 30; i--) {
                if (line[i] != ' ') {
                    mon = mon + line[i] * b;
                }
                b = b * 10;
            }
            masOfClients[amountOfClients].money = mon;
            mon = 0;
            b = 1;
            for (int i = 40; i > 35; i--) {
                if (line[i] != ' ') {
                    mon = mon + line[i] * b;
                }
                b = b * 10;
            }
            masOfClients[amountOfClients].winCount = mon;
            mon = 0;
            b = 1;
            for (int i = 45; i > 40; i--) {
                if (line[i] != ' ') {
                    mon = mon + line[i] * b;
                }
                b = b * 10;
            }
            masOfClients[amountOfClients].loseCount = mon;
            amountOfClients++;
        }
    }
    in.close();
}

int check(char newNickname[]) {
    for (int i = 0; i < 20; i++) {
        if (masOfClients[i].nickname == newNickname) {
            return i;
        }
    }
    return -1;
}

void workingWithClient(SOCKET newConnection) {
    char newNickname[15];
    recv(newConnection, newNickname, sizeof(newNickname), NULL);
    std::cout << newNickname << " connected\n";
    if (check(newNickname) > -1) {
        int index = check(newNickname);
        char password[15];
        char msg[256] = "Input your password: ";
        send(newConnection, msg, sizeof(msg), NULL);
        bool check = true;
        while (check) {
            recv(newConnection, password, sizeof(password), NULL);
            if (masOfClients[index].password == password) {
                while (gameIsWorkingWithNewGamers || serverIsWorkingWithNewGamers) {
                    Sleep(100);
                }
                serverIsWorkingWithNewGamers = true;
                while (serverIsWorkingWithNewGamers) {
                    for (int i = 0; i < 15; i++) {
                        newGamers[amountOfNewGamers].nickname[i] = newNickname[i];
                    }
                    newGamers[amountOfNewGamers].money = masOfClients[index].money;
                    newGamers[amountOfNewGamers].winCount = masOfClients[index].winCount;
                    newGamers[amountOfNewGamers].loseCount = masOfClients[index].loseCount;
                    newGamers[amountOfNewGamers].Connection = newConnection;
                    amountOfNewGamers++;
                    std::string msg1;
                    msg1 = msg1 + std::to_string(newGamers[amountOfNewGamers - 1].money);
                    msg1 = msg1 + "    ";
                    msg1 = msg1 + std::to_string(newGamers[amountOfNewGamers - 1].winCount);
                    msg1 = msg1 + " ";
                    msg1 = msg1 + std::to_string(newGamers[amountOfNewGamers - 1].loseCount);
                    msg1 = msg1 + " ";
                    serverIsWorkingWithNewGamers = false;
                    char* temp_line = new char[msg1.size() + 1];
                    strcpy(temp_line, msg1.c_str());
                    send(newConnection, temp_line, 256, NULL);
                    check = false;
                }
            }
            else {
                char msg[256] = "Wrong password, try again: ";
                send(newConnection, msg, sizeof(msg), NULL);
            }
        }
    }
    else {
        char newPassword[15];
        char msg[256] = "Come up with a password for your account: ";
        send(newConnection, msg, sizeof(msg), NULL);
        recv(newConnection, newPassword, sizeof(newPassword), NULL);
        while (gameIsWorkingWithNewGamers) {
            Sleep(100);
        }
        serverIsWorkingWithNewGamers = true;
        for (int i = 0; i < 15; i++) {
            masOfClients[amountOfClients].nickname[i] = newNickname[i];
            newGamers[amountOfNewGamers].nickname[i] = newNickname[i];
        }
        masOfClients[amountOfClients].money = 200;
        newGamers[amountOfNewGamers].money = 200;
        masOfClients[amountOfClients].winCount = 0;
        newGamers[amountOfNewGamers].winCount = 0;
        masOfClients[amountOfClients].loseCount = 0;
        newGamers[amountOfNewGamers].loseCount = 0;
        newGamers[amountOfNewGamers].Connection = newConnection;
        amountOfClients++;
        amountOfNewGamers++;
        std::string msg1;
        msg1 = msg1 + std::to_string(newGamers[amountOfNewGamers - 1].money);
        msg1 = msg1 + "    ";
        msg1 = msg1 + std::to_string(newGamers[amountOfNewGamers - 1].winCount);
        msg1 = msg1 + " ";
        msg1 = msg1 + std::to_string(newGamers[amountOfNewGamers - 1].loseCount);
        msg1 = msg1 + " ";
        serverIsWorkingWithNewGamers = false;
        char* temp_line = new char[msg1.size() + 1];
        strcpy(temp_line, msg1.c_str());
        send(newConnection, temp_line, 256, NULL);
    }

    counter++;
    if (counter == anotherCounter) {
        Sleep(8000);
        notNow = false;
    }

    Sleep(300);
    if (gameIsGoing) {
        char msg[256] = "The game is going, please wait till it will over";
        send(newConnection, msg, sizeof(msg), NULL);
    }
    else if (counter < skolkoIgrokov) {
        char msg[256] = "Not enough players to start the game, please wait till more players will join";
        send(newConnection, msg, sizeof(msg), NULL);
    }
    while (gameIsGoing || counter < skolkoIgrokov) {
        Sleep(1000);
    }
}

int conectingClientsToServer(SOCKET sListen, SOCKADDR_IN addres, int sizeOfAddres) {
    std::cout << "I am ready\n";
    SOCKET newConnection;
    char newNickname[15];
    while (!endOfWork) {
        for (int i = 0; i < 6; i++) {
            newConnection = accept(sListen, (SOCKADDR*)&addres, &sizeOfAddres);
            if (newConnection == 0) {
                std::cout << "Error with newConnection\n";
            }
            else {
                connections[anotherCounter] = newConnection;
                anotherCounter++;
                CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)workingWithClient, (LPVOID)newConnection, NULL, NULL);
            }
        }
    }
    return 0;
}

void isTheClientReady(SOCKET Connection) {
    char readingless[2];
    recv(Connection, readingless, sizeof(readingless), NULL);
    readyCount++;
}

int usedNumbers[15];
int usedNumbersCount = 0;

bool testTempNumb(int tempNumb) {
    for (int i = 0; i < 15; i++) {
        if (tempNumb == usedNumbers[i]) {
            return true;
        }
    }
    usedNumbers[usedNumbersCount] = tempNumb;
    usedNumbersCount++;
    return false;
}

bool checkFoldGamer(gamers foldPlayers[], int amountOfFoldPlayers, int man) {
    for (int i = 0; i < amountOfFoldPlayers; i++) {
        int check = 0;
        for (int y = 0; y < sizeof(foldPlayers[i].nickname); y++) {
            if (foldPlayers[i].nickname[y] == masOfGamers[man].nickname[y]) {
                check++;
            }
        }
        if (check == sizeof(foldPlayers[i].nickname)) {
            return true;
        }
    }
    return false;
}

void sendMsgToAllPlayers(int j, std::string man, int bank, int maxBet, int moneyLost = 0) {
    std::string msg;
    msg = msg + man;
    msg = msg + " ";
    msg = msg + std::to_string(bank);
    msg = msg + " ";
    if (man[0] == 'C' || man[0] == 'E') {
        msg = msg + std::to_string(moneyLost);
        msg = msg + " ";
    }
    if (man[0] == 'E') {
        msg = msg + std::to_string(maxBet);
        msg = msg + " ";
    }
    for (int y = 0; y < 15; y++) {
        msg = msg + masOfGamers[j].nickname[y];
    }
    for (int i = 0; i < counter; i++) {
        if (i == j) {
            continue;
        }
        char* temp_line = new char[msg.size() + 1];
        strcpy(temp_line, msg.c_str());
        std::cout << "\n" << temp_line;
        send(masOfGamers[i].Connection, temp_line, 256, NULL);
    }
}

void PockerGame() {
    while (counter < skolkoIgrokov) {
        Sleep(1000);
    }
    while (notNow) {
        Sleep(1000);
    }
    while (serverIsWorkingWithNewGamers) {
        Sleep(100);
    }
    gameIsWorkingWithNewGamers = true;
    for (int i = 0; i < amountOfNewGamers; i++) {
        masOfGamers[i] = newGamers[i];
        amountOfGamers++;
        newGamers[i].money = NULL;
        newGamers[i].loseCount = NULL;
        newGamers[i].winCount = NULL;
    }
    amountOfNewGamers = 0;
    gameIsWorkingWithNewGamers = false;
    for (int i = 0; i < counter; i++) {
        char msg[256] = "Are you ready to begin?";
        send(masOfGamers[i].Connection, msg, sizeof(msg), NULL);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)isTheClientReady, (LPVOID)masOfGamers[i].Connection, NULL, NULL);
    }
    while (readyCount != amountOfGamers) {
        Sleep(300);
    }
    std::string koloda = "2h3h4h5h6h7h8h9h1hvhdhkhth2b3b4b5b6b7b8b9b1bvbdbkbtb2c3c4c5c6c7c8c9c1cvcdckctc2p3p4p5p6p7p8p9p1pvpdpkptp";
    srand(time(0));
    int tempNumb;
    readyCount = 0;
    for (int i = 0; i < counter; i++) {
        std::string msg;
        tempNumb = rand() % 52 * 2;
        while (koloda[tempNumb] == '\0') {
            tempNumb = rand() % 52 * 2;
        }
        msg = msg + koloda[tempNumb];
        msg = msg + koloda[tempNumb + 1];
        msg = msg + " ";
        koloda[tempNumb] = '\0';
        koloda[tempNumb + 1] = '\0';
        tempNumb = rand() % 52 * 2;
        while (koloda[tempNumb] == '\0') {
            tempNumb = rand() % 52 * 2;
        }
        msg = msg + koloda[tempNumb];
        msg = msg + koloda[tempNumb + 1];
        msg = msg + " ";
        koloda[tempNumb] = '\0';
        koloda[tempNumb + 1] = '\0';
        msg = msg + (char)(counter - 1);
        msg = msg + " ";
        msg = msg + (char)(i + 1);
        msg = msg + " ";
        for (int j = 0; j < counter; j++) {
            if (i == j) {
                continue;
            }
            msg = msg + std::to_string(masOfGamers[j].money);
            msg = msg + "    ";
            msg = msg + std::to_string(masOfGamers[j].winCount);
            msg = msg + " ";
            msg = msg + std::to_string(masOfGamers[j].loseCount);
            msg = msg + " ";
            int y = 0;
            while(masOfGamers[j].nickname[y] != '\0'){
                msg = msg + masOfGamers[j].nickname[y];
                y++;
            }
            msg = msg + " ";
        }
        char* temp_line = new char[msg.size() + 1];
        strcpy(temp_line, msg.c_str());
        std::cout << "\n" << temp_line;
        send(masOfGamers[i].Connection, temp_line, 256, NULL);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)isTheClientReady, (LPVOID)masOfGamers[i].Connection, NULL, NULL);
    }
    while (readyCount != amountOfGamers) {
        Sleep(300);
    }
    Sleep(5000);
    readyCount = 0;
    
    gamers foldPlayers[6] = {};
    int amountOfFoldPlayers = 0;
    char playerMsg[256];
    int sizeOfMsg = 0;
    int moneyToBank = 0;
    char msgLittleBlaid[3] = "-5";
    char msgBigBlaid[4] = "-10";
    int bank = 5;
    char msgYourTurnWithoutBet[9] = "YT F C B";
    int stopPlayer = 1;
    bool oneTime = true;
    int maxBet = 10;
    std::string msgAboutNewRound;

    //ROUND 1
    send(masOfGamers[0].Connection, msgLittleBlaid, 256, NULL);
    sendMsgToAllPlayers(0, "LB", bank, maxBet);
    Sleep(5000);
    bank = bank + 10;
    send(masOfGamers[1].Connection, msgBigBlaid, 256, NULL);
    sendMsgToAllPlayers(1, "BB", bank, maxBet);
    Sleep(5000);
    for (int i = 2; i != stopPlayer; i++) {
        if (oneTime) {
            stopPlayer++;
            oneTime = false;
        }
        if (i == counter) {
            i = 0;
        }
        if (amountOfFoldPlayers + 1 == counter) {
            for (int m = 0; m < counter; m++) {
                if (!checkFoldGamer(foldPlayers, amountOfFoldPlayers, m)) {
                    std::cout << "\n" << masOfGamers[m].nickname << " won\n";
                    std::string finalMsg;
                    finalMsg = finalMsg + masOfGamers[m].nickname;
                    finalMsg = finalMsg + " has won ";
                    char* fMsg = new char[finalMsg.size() + 1];
                    strcpy(fMsg, finalMsg.c_str());
                    for (int n = 0; n < counter; n++) {
                        send(masOfGamers[n].Connection, fMsg, 256, NULL);
                    }
                    return;
                }
            }
        }
        if (checkFoldGamer(foldPlayers, amountOfFoldPlayers, i)) {
            continue;
        }
        sendMsgToAllPlayers(i, "T", bank, maxBet);
        send(masOfGamers[i].Connection, msgYourTurnWithoutBet, 256, NULL);
        recv(masOfGamers[i].Connection, playerMsg, sizeof(playerMsg), NULL);
        int o = 2;
        switch (playerMsg[0])
        {
        case 'F':
            for (int y = 0; y < 15; y++) {
                foldPlayers[amountOfFoldPlayers].nickname[y] = masOfGamers[i].nickname[y];
            }
            amountOfFoldPlayers++;
            sendMsgToAllPlayers(i, "F", bank, maxBet);
            break;
        case 'C':
            while (playerMsg[o] != '\0') {
                moneyToBank = moneyToBank * 10;
                moneyToBank = moneyToBank + (playerMsg[o] - 48);
                o++;
            }
            bank = bank + moneyToBank;
            o = 2;
            sendMsgToAllPlayers(i, "C", bank, maxBet, moneyToBank);
            moneyToBank = 0;
            break;
        case 'E':
            while (playerMsg[o] != ' ') {
                moneyToBank = moneyToBank * 10;
                moneyToBank = moneyToBank + (playerMsg[o] - 48);
                o++;
            }
            o++;
            bank = bank + moneyToBank;
            maxBet = 0;
            while (playerMsg[o] != '\0') {
                maxBet = maxBet * 10;
                maxBet = maxBet + (playerMsg[o] - 48);
                o++;
            }
            o = 2;
            stopPlayer = i;
            oneTime = true;
            sendMsgToAllPlayers(i, "E", bank, maxBet, moneyToBank);
            moneyToBank = 0;
            break;
        default:
            break;
        }
        Sleep(5000);
    }
    //ROUND 2, 3 и 4
    for (int roundNumber = 0; roundNumber < 3; roundNumber++) {
        msgAboutNewRound = msgAboutNewRound + "! ";
        if (roundNumber == 0) {
            for (int i = 0; i < 3; i++) {
                tempNumb = rand() % 52 * 2;
                while (koloda[tempNumb] == '\0') {
                    tempNumb = rand() % 52 * 2;
                }
                msgAboutNewRound = msgAboutNewRound + koloda[tempNumb];
                msgAboutNewRound = msgAboutNewRound + koloda[tempNumb + 1];
                msgAboutNewRound = msgAboutNewRound + " ";
                koloda[tempNumb] = '\0';
                koloda[tempNumb + 1] = '\0';
                tempNumb = rand() % 52 * 2;
            }
        }
        else {
            tempNumb = rand() % 52 * 2;
            while (koloda[tempNumb] == '\0') {
                tempNumb = rand() % 52 * 2;
            }
            msgAboutNewRound = msgAboutNewRound + koloda[tempNumb];
            msgAboutNewRound = msgAboutNewRound + koloda[tempNumb + 1];
            msgAboutNewRound = msgAboutNewRound + " ";
            koloda[tempNumb] = '\0';
            koloda[tempNumb + 1] = '\0';
            tempNumb = rand() % 52 * 2;
        }
        char* msgAboutNewR = new char[msgAboutNewRound.size() + 1];
        strcpy(msgAboutNewR, msgAboutNewRound.c_str());
        std::cout << "\n" << msgAboutNewRound << "\n";
        for (int i = 0; i < counter; i++) {
            send(masOfGamers[i].Connection, msgAboutNewR, 256, NULL);
        }
        msgAboutNewRound.clear();
        Sleep(5000);
        stopPlayer = counter;
        for (int i = 0; i != stopPlayer; i++) {
            if (oneTime) {
                stopPlayer++;
                oneTime = false;
            }
            if (i == counter) {
                i = 0;
            }
            if (amountOfFoldPlayers + 1 == counter) {
                for (int m = 0; m < counter; m++) {
                    if (!checkFoldGamer(foldPlayers, amountOfFoldPlayers, m)) {
                        std::cout << "\n" << masOfGamers[m].nickname << " won\n";
                        std::string finalMsg;
                        finalMsg = finalMsg + masOfGamers[m].nickname;
                        finalMsg = finalMsg + " has won ";
                        finalMsg = finalMsg + std::to_string(bank) + "$.";
                        char* fMsg = new char[finalMsg.size() + 1];
                        strcpy(fMsg, finalMsg.c_str());
                        for (int n = 0; n < counter; n++) {
                            send(masOfGamers[n].Connection, fMsg, 256, NULL);
                        }
                        return;
                    }
                }
            }
            if (checkFoldGamer(foldPlayers, amountOfFoldPlayers, i)) {
                continue;
            }
            sendMsgToAllPlayers(i, "T", bank, maxBet);
            send(masOfGamers[i].Connection, msgYourTurnWithoutBet, 256, NULL);
            recv(masOfGamers[i].Connection, playerMsg, sizeof(playerMsg), NULL);
            int o = 2;
            switch (playerMsg[0])
            {
            case 'F':
                for (int y = 0; y < 15; y++) {
                    foldPlayers[amountOfFoldPlayers].nickname[y] = masOfGamers[i].nickname[y];
                }
                amountOfFoldPlayers++;
                sendMsgToAllPlayers(i, "F", bank, maxBet);
                break;
            case 'C':
                while (playerMsg[o] != '\0') {
                    moneyToBank = moneyToBank * 10;
                    moneyToBank = moneyToBank + (playerMsg[o] - 48);
                    o++;
                }
                bank = bank + moneyToBank;
                o = 2;
                sendMsgToAllPlayers(i, "C", bank, maxBet, moneyToBank);
                moneyToBank = 0;
                break;
            case 'E':
                while (playerMsg[o] != ' ') {
                    moneyToBank = moneyToBank * 10;
                    moneyToBank = moneyToBank + (playerMsg[o] - 48);
                    o++;
                }
                o++;
                bank = bank + moneyToBank;
                maxBet = 0;
                while (playerMsg[o] != '\0') {
                    maxBet = maxBet * 10;
                    maxBet = maxBet + (playerMsg[o] - 48);
                    o++;
                }
                o = 2;
                stopPlayer = i;
                oneTime = true;
                sendMsgToAllPlayers(i, "E", bank, maxBet, moneyToBank);
                moneyToBank = 0;
                break;
            default:
                break;
            }
            Sleep(5000);
        }
    }
    //ПОДСЧЁТ ОЧКОВ
    int massivOtvetov[6];
    msgAboutNewRound = msgAboutNewRound + "a";
    char* msgAboutNewR = new char[msgAboutNewRound.size() + 1];
    strcpy(msgAboutNewR, msgAboutNewRound.c_str());
    std::cout << "\n" << msgAboutNewRound << "\n";
    for (int i = 0; i < counter; i++) {
        send(masOfGamers[i].Connection, msgAboutNewR, 256, NULL);
    }
    Sleep(2000);
    for (int i = 0; i < counter; i++) {
        massivOtvetov[i] = 0;
        send(masOfGamers[i].Connection, msgAboutNewR, 256, NULL);
        recv(masOfGamers[i].Connection, playerMsg, sizeof(playerMsg), NULL);
        std::cout << "\n" << playerMsg;
        if (checkFoldGamer(foldPlayers, amountOfFoldPlayers, i)) {
            massivOtvetov[i] = 0;
            std::cout << " F" << "\n";
            continue;
        }
        int g = 0;
        while (playerMsg[g] != '\0') {
            massivOtvetov[i] = massivOtvetov[i] * 10;
            massivOtvetov[i] = massivOtvetov[i] + (playerMsg[g] - 48);
            g++;
        }
    }
    int bestScore = 0;
    int winner = 0;
    int secondWinner = -1;
    for (int i = 0; i < counter; i++) {
        if (massivOtvetov[i] == bestScore) {
            secondWinner = i;
        }
        else if (massivOtvetov[i] > bestScore) {
            bestScore = massivOtvetov[i];
            winner = i;
            secondWinner = -1;
        }
    }
    std::string finalMsg;
    if (winner != -1) {
        std::cout << "\n" << masOfGamers[winner].nickname << " won\n";
        finalMsg = finalMsg + masOfGamers[winner].nickname;
        finalMsg = finalMsg + " has won ";
    }
    if (secondWinner != -1) {
        std::cout << "\n" << masOfGamers[secondWinner].nickname << " won\n";
        finalMsg = finalMsg + std::to_string(bank / 2) + "$. " + masOfGamers[secondWinner].nickname + " has won " + std::to_string(bank / 2) + "$.";
    }
    else {
        finalMsg = finalMsg + std::to_string(bank) + "$.";
    }
    char* fMsg = new char[finalMsg.size() + 1];
    strcpy(fMsg, finalMsg.c_str());
    for (int i = 0; i < counter; i++) {
        send(masOfGamers[i].Connection, fMsg, 256, NULL);
    }
}


int main(int argc, char* argv[])
{
    getClientInfoFromFile();

    std::string myIP;
    std::cout << "Input IP or press '!' and then ENTER: ";
    std::cin >> myIP;

    std::cout << "How much of players there will be, Master? ";
    std::cin >> skolkoIgrokov;// <= 6

    for (int i = 0; i < 6; i++) {
        masOfGamers[i].money = NULL;
        newGamers[i].money = NULL;
        masOfGamers[i].loseCount = NULL;
        newGamers[i].loseCount = NULL;
        masOfGamers[i].winCount = NULL;
        newGamers[i].winCount = NULL;
    }

    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "Error with wsaData\n" << std::endl;
        return 1;
    }

    SOCKADDR_IN addres;
    int sizeOfAddres = sizeof(addres);
    //параметр запуска сервера через пробел, ip-адрес машины
    if (myIP[0] != '!')
    {
        char* mIP = new char[myIP.size() + 1];
        strcpy(mIP, myIP.c_str());
        addres.sin_addr.s_addr = inet_addr(mIP);
    }
    else
    {
        addres.sin_addr.s_addr = inet_addr("255.155.0.1");//меняй при каждом запуске компа
    }


    addres.sin_port = htons(1337);
    addres.sin_family = AF_INET;

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addres, sizeof(addres));
    listen(sListen, SOMAXCONN);
    std::thread CCTS(conectingClientsToServer, sListen, addres, sizeOfAddres);


    PockerGame();
    std::cout << "\nThe end.\n";

    CCTS.join();
    return 0;
}