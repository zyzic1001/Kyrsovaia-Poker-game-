#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#include <thread>
#include "Header.h"

#pragma warning(disable: 4996)

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

struct gamers {
    char nickname[15] = {};
    int sizeOfNickname = 0;
    int money = 0;
    int sizeOfMoney = 0;
    int winCount = 0;
    int sizeOfWinCount = 0;
    int loseCount = 0;
    int sizeOfLoseCount = 0;
};

gamers myEnemies[5];

void gameStartScreen() {
    system("cls");

    gotoxy(43, 7);
    std::cout << "$$$  welcome to poker  $$$";
    у(15, 10);
    р(29, 10);
    о(39, 10);
    м(49, 10);
    ч(61, 10);
    и(71, 10);
    к(83, 10);
    а(93, 10);
    SetConsoleTextAttribute(h, 03);
    heart(33, 17);
    SetConsoleTextAttribute(h, 05);
    peaks(45, 17);
    SetConsoleTextAttribute(h, 10);
    booby(57, 17);
    SetConsoleTextAttribute(h, 12);
    cross(69, 17);
    Sleep(500);
    SetConsoleTextAttribute(h, 15);
    heart(33, 17);
    SetConsoleTextAttribute(h, 8);
    peaks(45, 17);
    SetConsoleTextAttribute(h, 14);
    booby(57, 17);
    SetConsoleTextAttribute(h, 7);
    cross(69, 17);
    Sleep(500);
    SetConsoleTextAttribute(h, 11);
    heart(33, 17);
    SetConsoleTextAttribute(h, 6);
    peaks(45, 17);
    SetConsoleTextAttribute(h, 2);
    booby(57, 17);
    SetConsoleTextAttribute(h, 13);
    cross(69, 17);
    Sleep(500);
    SetConsoleTextAttribute(h, 4);
    heart(33, 17);
    SetConsoleTextAttribute(h, 15);
    peaks(45, 17);
    SetConsoleTextAttribute(h, 4);
    booby(57, 17);
    SetConsoleTextAttribute(h, 15);
    cross(69, 17);
    Sleep(2000);
}

void whatCard(string card, int x, int y) {
    gotoxy(x, y);
    for (int i = 0; i < 7; i++) {
        cout << (char)176;
    }
    gotoxy(x, y + 1);
    cout << (char)176;
    if (card[1] == 'b' || card[1] == 'h') {
        SetConsoleTextAttribute(h, 4);
    }
    switch (card[0])
    {
    case '1':
        cout << "10";
        break;
    case '2':
        cout << "2 ";
        break;
    case '3':
        cout << "3 ";
        break;
    case '4':
        cout << "4 ";
        break;
    case '5':
        cout << "5 ";
        break;
    case '6':
        cout << "6 ";
        break;
    case '7':
        cout << "7 ";
        break;
    case '8':
        cout << "8 ";
        break;
    case '9':
        cout << "9 ";
        break;
    case 'v':
        cout << "V ";
        break;
    case 'd':
        cout << "D ";
        break;
    case 'k':
        cout << "K ";
        break;
    case 't':
        cout << "T ";
        break;
    default:
        break;
    }
    SetConsoleTextAttribute(h, 15);
    std::cout << "   " << (char)176;
    gotoxy(x, y + 2);
    cout << (char)176;
    if (card[1] == 'b' || card[1] == 'h') {
        SetConsoleTextAttribute(h, 4);
    }
    switch (card[1])
    {
    case 'h':
        cout << (char)3;
        break;
    case 'b':
        cout << (char)4;
        break;
    case 'c':
        cout << (char)5;
        break;
    case 'p':
        cout << (char)6;
        break;
    default:
        break;
    }
    SetConsoleTextAttribute(h, 15);
    std::cout << "    " << (char)176;
    gotoxy(x, y + 3);
    std::cout << (char)176 << "     " << (char)176;
    gotoxy(x, y + 4);
    std::cout << (char)176 << "     " << (char)176;
    gotoxy(x, y + 5);
    std::cout << (char)176 << "     " << (char)176;
    gotoxy(x, y + 6);
    std::cout << (char)176 << "     " << (char)176;
    gotoxy(x, y + 7);
    std::cout << (char)176 << "     " << (char)176;
}

void whatToDraw(int i) {
    switch (i)
    {
    case 0:
        gotoxy(31, 12); cout << "    ///\"\\    ";
        gotoxy(31, 13); cout << "    |6 6|    ";
        gotoxy(31, 14); cout << "    \\ - /    ";
        gotoxy(31, 15); cout << "   __) (__   ";
        gotoxy(31, 16); cout << "  /  \\./  \\  ";
        gotoxy(31, 17); cout << " / :  :  : \\ ";
        gotoxy(31, 18); cout << "( (|  :  |) )";
        break;
    case 1:
        gotoxy(46, 12); cout << "    //||\\__  ";
        gotoxy(46, 13); cout << "    |6 6|    ";
        gotoxy(46, 14); cout << "    \\ - /    ";
        gotoxy(46, 15); cout << "   __) (__   ";
        gotoxy(46, 16); cout << "  /  \\./  \\  ";
        gotoxy(46, 17); cout << " / :  :  : \\ ";
        gotoxy(46, 18); cout << "( (|  :  |) )";
        break;
    case 2:
        gotoxy(61, 12); cout << "    /\\\\\\\\    ";
        gotoxy(61, 13); cout << "    |6 6|    ";
        gotoxy(61, 14); cout << "    \\ - /    ";
        gotoxy(61, 15); cout << "   __) (__   ";
        gotoxy(61, 16); cout << "  /  \\./  \\  ";
        gotoxy(61, 17); cout << " / :  :  : \\ ";
        gotoxy(61, 18); cout << "( (|  :  |) )";
        break;
    case 3:
        gotoxy(76, 12); cout << "    //\\\\\\    ";
        gotoxy(76, 13); cout << "   //6 6\\\\   ";
        gotoxy(76, 14); cout << "  //\\ - /\\\\   ";
        gotoxy(76, 15); cout << "   __) (__   ";
        gotoxy(76, 16); cout << "  /  \\./  \\  ";
        gotoxy(76, 17); cout << " / :  :  : \\ ";
        gotoxy(76, 18); cout << "( (|  :  |) )";
        break;
    case 4:
        gotoxy(91, 12); cout << "    //|\\\\    ";
        gotoxy(91, 13); cout << "   /|6 6|\\   ";
        gotoxy(91, 14); cout << "    \\ - /    ";
        gotoxy(91, 15); cout << "   __) (__   ";
        gotoxy(91, 16); cout << "  /  \\./  \\  ";
        gotoxy(91, 17); cout << " / :  :  : \\ ";
        gotoxy(91, 18); cout << "( (|  :  |) )";
        break;
    default:
        break;
    }
}

void gamePlayScreen(gamers* myData, char myCard11, char myCard12, char myCard21, char myCard22, int myEnemiesNumber, int myTurn, int maxBet, int round, string cardOnTable1, string cardOnTable2, string cardOnTable3, string cardOnTable4, string cardOnTable5) {
    gotoxy(0, 0); cout << "Your turn is " << myTurn;
    for (int i = 0; i < 30; i++) {
        gotoxy(105, i);
        std::cout << (char)219;
    }
    gotoxy(106, 1);
    std::cout << "Your money:";
    gotoxy(106, 2);
    std::cout << myData->money << "$";
    gotoxy(106, 4);
    std::cout << "Your win/lose:";
    gotoxy(106, 5);
    std::cout << myData->winCount << "/" << myData->loseCount;
    gotoxy(106, 7);
    std::cout << "Max bet:";
    gotoxy(106, 8);
    std::cout << "       ";
    gotoxy(106, 8);
    std::cout << maxBet << "$";
    gotoxy(106, 21);
    std::cout << "Your cards:";
    gotoxy(106, 23);
    std::cout << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176 << (char)176;
    gotoxy(106, 24);
    std::cout << (char)176;
    if (myCard12 == 'b' || myCard12 == 'h') {
        SetConsoleTextAttribute(h, 4);
    }
    switch (myCard11)
    {
    case '1':
        cout << "10";
        break;
    case '2':
        cout << "2 ";
        break;
    case '3':
        cout << "3 ";
        break;
    case '4':
        cout << "4 ";
        break;
    case '5':
        cout << "5 ";
        break;
    case '6':
        cout << "6 ";
        break;
    case '7':
        cout << "7 ";
        break;
    case '8':
        cout << "8 ";
        break;
    case '9':
        cout << "9 ";
        break;
    case 'v':
        cout << "V ";
        break;
    case 'd':
        cout << "D ";
        break;
    case 'k':
        cout << "K ";
        break;
    case 't':
        cout << "T ";
        break;
    default:
        break;
    }
    SetConsoleTextAttribute(h, 15);
    std::cout << "   " << (char)176 << (char)176;
    if (myCard22 == 'b' || myCard22 == 'h') {
        SetConsoleTextAttribute(h, 4);
    }
    switch (myCard21)
    {
    case '1':
        cout << "10";
        break;
    case '2':
        cout << "2 ";
        break;
    case '3':
        cout << "3 ";
        break;
    case '4':
        cout << "4 ";
        break;
    case '5':
        cout << "5 ";
        break;
    case '6':
        cout << "6 ";
        break;
    case '7':
        cout << "7 ";
        break;
    case '8':
        cout << "8 ";
        break;
    case '9':
        cout << "9 ";
        break;
    case 'v':
        cout << "V ";
        break;
    case 'd':
        cout << "D ";
        break;
    case 'k':
        cout << "K ";
        break;
    case 't':
        cout << "T ";
        break;
    default:
        break;
    }
    SetConsoleTextAttribute(h, 15);
    std::cout << "   " << (char)176;
    gotoxy(106, 25);
    std::cout << (char)176;
    if (myCard12 == 'b' || myCard12 == 'h') {
        SetConsoleTextAttribute(h, 4);
    }
    switch (myCard12)
    {
    case 'h':
        cout << (char)3;
        break;
    case 'b':
        cout << (char)4;
        break;
    case 'c':
        cout << (char)5;
        break;
    case 'p':
        cout << (char)6;
        break;
    default:
        break;
    }
    SetConsoleTextAttribute(h, 15);
    std::cout << "    " << (char)176 << (char)176;
    if (myCard22 == 'b' || myCard22 == 'h') {
        SetConsoleTextAttribute(h, 4);
    }
    switch (myCard22)
    {
    case 'h':
        cout << (char)3;
        break;
    case 'b':
        cout << (char)4;
        break;
    case 'c':
        cout << (char)5;
        break;
    case 'p':
        cout << (char)6;
        break;
    default:
        break;
    }
    SetConsoleTextAttribute(h, 15);
    std::cout << "    " << (char)176;
    gotoxy(106, 26);
    std::cout << (char)176 << "     " << (char)176 << (char)176 << "     " << (char)176;
    gotoxy(106, 27);
    std::cout << (char)176 << "     " << (char)176 << (char)176 << "     " << (char)176;
    gotoxy(106, 28);
    std::cout << (char)176 << "     " << (char)176 << (char)176 << "     " << (char)176;
    gotoxy(106, 29);
    std::cout << (char)176 << "     " << (char)176 << (char)176 << "     " << (char)176;
    gotoxy(106, 30);
    std::cout << (char)176 << "     " << (char)176 << (char)176 << "     " << (char)176;
    gotoxy(3, 14);
    cout << "I am croupier";
    gotoxy(3, 15);
    cout << "Round: " << round << "/4";
    gotoxy(3, 17);
    std::cout << "#############";
    gotoxy(3, 18);
    std::cout << "##         ##";
    gotoxy(3, 19);
    std::cout << "#  ~~   ~~  #";
    gotoxy(3, 20);
    std::cout << "#  ()   ()  #";
    gotoxy(3, 21);
    std::cout << "(     ^     )";
    gotoxy(3, 22);
    std::cout << " |         | ";
    gotoxy(3, 23);
    std::cout << " |  {===}  | ";
    gotoxy(3, 24);
    std::cout << "  \\       /  ";
    gotoxy(3, 25);
    std::cout << " /  -----  \\ ";
    gotoxy(1, 26);
    std::cout << "---  |%\\ /%|  ---";
    gotoxy(0, 27);
    std::cout << "/     |%%%%%|     \\";
    gotoxy(0, 28);
    std::cout << "      |%/ \\%|      ";
    gotoxy(22, 29); cout << (char)219;
    gotoxy(22, 28); cout << (char)219;
    gotoxy(22, 27); cout << (char)219;
    gotoxy(23, 27); cout << (char)219;
    gotoxy(23, 26); cout << (char)219;
    gotoxy(23, 25); cout << (char)219;
    gotoxy(23, 24); cout << (char)219;
    gotoxy(24, 24); cout << (char)219;
    gotoxy(24, 23); cout << (char)219;
    gotoxy(24, 22); cout << (char)219;
    gotoxy(24, 21); cout << (char)219;
    gotoxy(25, 21); cout << (char)219;
    gotoxy(26, 21); cout << (char)219;
    gotoxy(26, 20); cout << (char)219;
    gotoxy(27, 20); cout << (char)219;
    gotoxy(28, 20); cout << (char)219;
    gotoxy(29, 20); cout << (char)219;
    gotoxy(30, 20); cout << (char)219;
    gotoxy(30, 19); cout << (char)219;
    for (int i = 31; i < 104; i++) {
        cout << (char)219;
    }
    gotoxy(103, 20); cout << (char)219;
    gotoxy(104, 20); cout << (char)219;

    int turnNumber = 1;
    int coordinats = 31;
    for (int i = 0; i < myEnemiesNumber; i++) {
        if (turnNumber == myTurn) {
            turnNumber++;
        }
        gotoxy(coordinats, 7); cout << "turn: " << turnNumber;
        gotoxy(coordinats, 8); cout << myEnemies[i].nickname;
        gotoxy(coordinats, 9); cout << myEnemies[i].winCount << "/" << myEnemies[i].loseCount;
        gotoxy(coordinats, 10); cout << "      ";
        gotoxy(coordinats, 10); cout << myEnemies[i].money << "$";
        whatToDraw(i);
        coordinats = coordinats + 15;
        turnNumber++;
    }

    switch (round)
    {
    case 2:
        whatCard(cardOnTable1, 42, 23);
        whatCard(cardOnTable2, 52, 23);
        whatCard(cardOnTable3, 62, 23);
        break;
    case 3:
        whatCard(cardOnTable1, 42, 23);
        whatCard(cardOnTable2, 52, 23);
        whatCard(cardOnTable3, 62, 23);
        whatCard(cardOnTable4, 72, 23);
        break;
    case 4:
        whatCard(cardOnTable1, 42, 23);
        whatCard(cardOnTable2, 52, 23);
        whatCard(cardOnTable3, 62, 23);
        whatCard(cardOnTable4, 72, 23);
        whatCard(cardOnTable5, 82, 23);
        break;
    default:
        break;
    }
    gotoxy(0, 0);
}

bool checkSuit(string allCards[], int targetPosition) {
    if (allCards[targetPosition + 1] != " " && allCards[targetPosition + 6] != " " && allCards[targetPosition + 11] != " " && allCards[targetPosition + 16] != " " && allCards[targetPosition + 21] != " ") {
        return true;
    }
    else if (allCards[targetPosition + 2] != " " && allCards[targetPosition + 7] != " " && allCards[targetPosition + 12] != " " && allCards[targetPosition + 17] != " " && allCards[targetPosition + 22] != " ") {
        return true;
    }
    else if (allCards[targetPosition + 3] != " " && allCards[targetPosition + 8] != " " && allCards[targetPosition + 13] != " " && allCards[targetPosition + 18] != " " && allCards[targetPosition + 23] != " ") {
        return true;
    }
    else if (allCards[targetPosition + 4] != " " && allCards[targetPosition + 9] != " " && allCards[targetPosition + 14] != " " && allCards[targetPosition + 19] != " " && allCards[targetPosition + 24] != " ") {
        return true;
    }
    return false;
}

void proverkaMsg(char serverMsg[], int* maxBet, int* yourBet, gamers* myData, SOCKET Connection, int* round, string* cardOnTable1, string* cardOnTable2, string* cardOnTable3, string* cardOnTable4, string* cardOnTable5, char myCard11, char myCard12, char myCard21, char myCard22, int* myScore) {
    if (serverMsg[0] == '-' && serverMsg[1] == '5') {
        gotoxy(0, 1);
        cout << "You made little blaide " << myData->money << " - " << 5 << " = " << myData->money - 5 << "\nThe bank is: 5$";
        myData->money = myData->money - 5;
        *yourBet = 5;
    }
    else if (serverMsg[0] == '-' && serverMsg[1] == '1' && serverMsg[2] == '0') {
        gotoxy(0, 1);
        cout << "You made big blaide " << myData->money << " - " << 10 << " = " << myData->money - 10 << "\nThe bank is: 15$";
        myData->money = myData->money - 10;
        *yourBet = 10;
    }
    else if (serverMsg[0] == 'Y' && serverMsg[1] == 'T') {
        int choiseIsYours = 0;
        gotoxy(0, 1);
        cout << "What will you do:   1.Fold   2.Check   3.Bet";
        while (choiseIsYours != 1 && choiseIsYours != 2 && choiseIsYours != 3) {
            gotoxy(0, 2); cout << "    "; gotoxy(0, 2);
            cin >> choiseIsYours;
        }
        if (choiseIsYours == 1) {
            char myMsg[2] = "F";
            send(Connection, myMsg, 256, NULL);
            gotoxy(0, 2); cout << "    ";
            gotoxy(0, 1);
            cout << "You folded.                                  ";
        }
        else if (choiseIsYours == 2) {
            std::string msg;
            int addedToYourBet = 0;
            addedToYourBet = *maxBet - *yourBet;
            *yourBet = *yourBet + addedToYourBet;
            myData->money = myData->money - addedToYourBet;
            msg = msg + "C ";
            msg = msg + std::to_string(addedToYourBet);
            char* myMsg = new char[msg.size() + 1];
            strcpy(myMsg, msg.c_str());
            send(Connection, myMsg, 256, NULL);
            gotoxy(0, 2); cout << "    ";
            gotoxy(0, 1);
            cout << "You checked.                                  ";
        }
        else if (choiseIsYours == 3) {
            int howMuch = 0;
            gotoxy(0, 3);
            cout << "Ok, so how much? ";
            cin >> howMuch;
            std::string msg;
            int addedToYourBet = 0;
            addedToYourBet = howMuch - *yourBet;
            *yourBet = *yourBet + addedToYourBet;
            myData->money = myData->money - addedToYourBet;
            *maxBet = *yourBet;
            msg = msg + "E ";
            msg = msg + std::to_string(addedToYourBet);
            msg = msg + " ";
            msg = msg + std::to_string(*maxBet);
            char* myMsg = new char[msg.size() + 1];
            strcpy(myMsg, msg.c_str());
            send(Connection, myMsg, 256, NULL);
            gotoxy(0, 2); cout << "    ";
            gotoxy(0, 1);
            cout << "You made a bet.                                  ";
        }
    }
    else if (serverMsg[0] == 'L' && serverMsg[1] == 'B') {
        gotoxy(0, 1);
        int bank = 0;
        int check = 0;
        int i = 3;
        while (serverMsg[i] != ' ') {
            bank = bank * 10;
            bank = bank + (serverMsg[i] - 48);
            i++;
        }
        i++;
        int t = i;
        for (int m = 0; m < 5; m++) {
            i = t;
            for (int y = 0; y < sizeof(myEnemies[m].nickname); y++) {
                if (serverMsg[i] == myEnemies[m].nickname[y]) {
                    check++;
                }
                i++;
                if (serverMsg[i] == '\0') {
                    y = 100;
                }
            }
            if (check == myEnemies[m].sizeOfNickname) {
                cout << myEnemies[m].nickname << " made little blaind. The bank is: " << bank << "$";
                myEnemies[m].money = myEnemies[m].money - 5;
                m = 5;
            }
            check = 0;
        }
    }
    else if (serverMsg[0] == 'B' && serverMsg[1] == 'B') {
        gotoxy(0, 1);
        int bank = 0;
        int check = 0;
        int i = 3;
        while (serverMsg[i] != ' ') {
            bank = bank * 10;
            bank = bank + (serverMsg[i] - 48);
            i++;
        }
        i++;
        int t = i;
        for (int m = 0; m < 5; m++) {
            i = t;
            for (int y = 0; y < sizeof(myEnemies[m].nickname); y++) {
                if (serverMsg[i] == myEnemies[m].nickname[y]) {
                    check++;
                }
                i++;
                if (serverMsg[i] == '\0') {
                    y = 100;
                }
            }
            if (check == myEnemies[m].sizeOfNickname) {
                cout << myEnemies[m].nickname << " made big blaind. The bank is: " << bank << "$";
                myEnemies[m].money = myEnemies[m].money - 10;
                m = 5;
            }
            check = 0;
        }
    }
    else if (serverMsg[0] == 'T') {
    gotoxy(0, 1);
    int bank = 0;
    int check = 0;
    int i = 2;
    while (serverMsg[i] != ' ') {
        bank = bank * 10;
        bank = bank + (serverMsg[i] - 48);
        i++;
    }
    i++;
    int t = i;
    for (int m = 0; m < 5; m++) {
        i = t;
        for (int y = 0; y < sizeof(myEnemies[m].nickname); y++) {
            if (serverMsg[i] == myEnemies[m].nickname[y]) {
                check++;
            }
            i++;
            if (serverMsg[i] == '\0') {
                y = 100;
            }
        }
        if (check == myEnemies[m].sizeOfNickname) {
            cout << myEnemies[m].nickname << "'s turn. The bank is: " << bank << "$";
            m = 5;
        }
        check = 0;
    }
    }
    else if (serverMsg[0] == 'F') {
        gotoxy(0, 1);
        int bank = 0;
        int check = 0;
        int i = 2;
        while (serverMsg[i] != ' ') {
            bank = bank * 10;
            bank = bank + (serverMsg[i] - 48);
            i++;
        }
        i++;
        int t = i;
        for (int m = 0; m < 5; m++) {
            i = t;
            for (int y = 0; y < sizeof(myEnemies[m].nickname); y++) {
                if (serverMsg[i] == myEnemies[m].nickname[y]) {
                    check++;
                }
                i++;
                if (serverMsg[i] == '\0') {
                    y = 100;
                }
            }
            if (check == myEnemies[m].sizeOfNickname) {
                cout << myEnemies[m].nickname << " made fold. The bank is: " << bank << "$";
                m = 5;
            }
            check = 0;
        }
    }
    else if (serverMsg[0] == 'C') {
        gotoxy(0, 1);
        int bank = 0;
        int check = 0;
        int moneyLost = 0;
        int i = 2;
        while (serverMsg[i] != ' ') {
            bank = bank * 10;
            bank = bank + (serverMsg[i] - 48);
            i++;
        }
        i++;
        while (serverMsg[i] != ' ') {
            moneyLost = moneyLost * 10;
            moneyLost = moneyLost + (serverMsg[i] - 48);
            i++;
        }
        i++;
        int t = i;
        for (int m = 0; m < 5; m++) {
            i = t;
            for (int y = 0; y < sizeof(myEnemies[m].nickname); y++) {
                if (serverMsg[i] == myEnemies[m].nickname[y]) {
                    check++;
                }
                i++;
                if (serverMsg[i] == '\0') {
                    y = 100;
                }
            }
            if (check == myEnemies[m].sizeOfNickname) {
                myEnemies[m].money = myEnemies[m].money - moneyLost;
                cout << myEnemies[m].nickname << " made check. The bank is: " << bank << "$";
                m = 5;
            }
            check = 0;
        }
    }
    else if (serverMsg[0] == 'E') {
        gotoxy(0, 1);
        int bank = 0;
        *maxBet = 0;
        int moneyLost = 0;
        int check = 0;
        int i = 2;
        while (serverMsg[i] != ' ') {
            bank = bank * 10;
            bank = bank + (serverMsg[i] - 48);
            i++;
        }
        i++;
        while (serverMsg[i] != ' ') {
            moneyLost = moneyLost * 10;
            moneyLost = moneyLost + (serverMsg[i] - 48);
            i++;
        }
        i++;
        while (serverMsg[i] != ' ') {
            *maxBet = *maxBet * 10;
            *maxBet = *maxBet + (serverMsg[i] - 48);
            i++;
        }
        i++;
        int t = i;
        for (int m = 0; m < 5; m++) {
            i = t;
            for (int y = 0; y < sizeof(myEnemies[m].nickname); y++) {
                if (serverMsg[i] == myEnemies[m].nickname[y]) {
                    check++;
                }
                i++;
                if (serverMsg[i] == '\0') {
                    y = 100;
                }
            }
            if (check == myEnemies[m].sizeOfNickname) {
                myEnemies[m].money = myEnemies[m].money - moneyLost;
                cout << myEnemies[m].nickname << " made bet = " << *maxBet << ". The bank is: " << bank << "$";
                m = 5;
            }
            check = 0;
        }
    }
    else if (serverMsg[0] == '!') {
        *round = *round + 1;
        gotoxy(0, 1);
        cout << "New round has started";
        int i = 2;
        switch (*round)
        {
        case 2:
            *cardOnTable1 = *cardOnTable1 + serverMsg[i];
            *cardOnTable1 = *cardOnTable1 + serverMsg[i + 1];
            i = i + 3;
            *cardOnTable2 = *cardOnTable2 + serverMsg[i];
            *cardOnTable2 = *cardOnTable2 + serverMsg[i + 1];
            i = i + 3;
            *cardOnTable3 = *cardOnTable3 + serverMsg[i];
            *cardOnTable3 = *cardOnTable3 + serverMsg[i + 1];
            break;
        case 3:
            *cardOnTable4 = *cardOnTable4 + serverMsg[i];
            *cardOnTable4 = *cardOnTable4 + serverMsg[i + 1];
            break;
        case 4:
            *cardOnTable5 = *cardOnTable5 + serverMsg[i];
            *cardOnTable5 = *cardOnTable5 + serverMsg[i + 1];
            break;
        default:
            break;
        }
    }
    else if (serverMsg[0] == 'a') {
        gotoxy(0, 1);
        cout << "Starting the scoring...";
        std::string allCards = "                                                                      ";
        std::string cardsOnTable = *cardOnTable1 + *cardOnTable2 + *cardOnTable3 + *cardOnTable4 + *cardOnTable5;
        cardsOnTable = cardsOnTable + myCard11 + myCard12 + myCard21 + myCard22;
        for (int i = 0; i < 14; i = i + 2) {
            switch (cardsOnTable[i])
            {
            case '2':
                allCards[5] = '2';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[6] = 'b';
                    break;
                case 'h':
                    allCards[7] = 'h';
                    break;
                case 'c':
                    allCards[8] = 'c';
                    break;
                case 'p':
                    allCards[9] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '3':
                allCards[10] = '3';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[11] = 'b';
                    break;
                case 'h':
                    allCards[12] = 'h';
                    break;
                case 'c':
                    allCards[13] = 'c';
                    break;
                case 'p':
                    allCards[14] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '4':
                allCards[15] = '4';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[16] = 'b';
                    break;
                case 'h':
                    allCards[17] = 'h';
                    break;
                case 'c':
                    allCards[18] = 'c';
                    break;
                case 'p':
                    allCards[19] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '5':
                allCards[20] = '5';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[21] = 'b';
                    break;
                case 'h':
                    allCards[22] = 'h';
                    break;
                case 'c':
                    allCards[23] = 'c';
                    break;
                case 'p':
                    allCards[24] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '6':
                allCards[25] = '6';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[26] = 'b';
                    break;
                case 'h':
                    allCards[27] = 'h';
                    break;
                case 'c':
                    allCards[28] = 'c';
                    break;
                case 'p':
                    allCards[29] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '7':
                allCards[30] = '7';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[31] = 'b';
                    break;
                case 'h':
                    allCards[32] = 'h';
                    break;
                case 'c':
                    allCards[33] = 'c';
                    break;
                case 'p':
                    allCards[34] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '8':
                allCards[35] = '8';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[36] = 'b';
                    break;
                case 'h':
                    allCards[37] = 'h';
                    break;
                case 'c':
                    allCards[38] = 'c';
                    break;
                case 'p':
                    allCards[39] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '9':
                allCards[40] = '9';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[41] = 'b';
                    break;
                case 'h':
                    allCards[42] = 'h';
                    break;
                case 'c':
                    allCards[43] = 'c';
                    break;
                case 'p':
                    allCards[44] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case '1':
                allCards[45] = '1';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[46] = 'b';
                    break;
                case 'h':
                    allCards[47] = 'h';
                    break;
                case 'c':
                    allCards[48] = 'c';
                    break;
                case 'p':
                    allCards[49] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case 'v':
                allCards[50] = 'v';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[51] = 'b';
                    break;
                case 'h':
                    allCards[52] = 'h';
                    break;
                case 'c':
                    allCards[53] = 'c';
                    break;
                case 'p':
                    allCards[54] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case 'd':
                allCards[55] = 'd';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[56] = 'b';
                    break;
                case 'h':
                    allCards[57] = 'h';
                    break;
                case 'c':
                    allCards[58] = 'c';
                    break;
                case 'p':
                    allCards[59] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case 'k':
                allCards[60] = 'k';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[61] = 'b';
                    break;
                case 'h':
                    allCards[62] = 'h';
                    break;
                case 'c':
                    allCards[63] = 'c';
                    break;
                case 'p':
                    allCards[64] = 'p';
                    break;
                default:
                    break;
                }
                break;
            case 't':
                allCards[0] = 't';
                allCards[65] = 't';
                switch (cardsOnTable[i + 1])
                {
                case 'b':
                    allCards[1] = 'b';
                    allCards[66] = 'b';
                    break;
                case 'h':
                    allCards[2] = 'h';
                    allCards[67] = 'h';
                    break;
                case 'c':
                    allCards[3] = 'c';
                    allCards[68] = 'c';
                    break;
                case 'p':
                    allCards[4] = 'p';
                    allCards[69] = 'p';
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        int check = 0;
        int fleshPosition = -1;
        int kapePosition = -1;
        int starshaiaKarta = 0;
        for (int i = 0; i < 70; i = i + 5) {
            if (allCards[i] != ' ') {
                if (allCards[i] == '1') {
                    starshaiaKarta = starshaiaKarta + 10;
                }
                else if (allCards[i] == 'v') {
                    starshaiaKarta = starshaiaKarta + 11;
                }
                else if (allCards[i] == 'd') {
                    starshaiaKarta = starshaiaKarta + 12;
                }
                else if (allCards[i] == 'k') {
                    starshaiaKarta = starshaiaKarta + 13;
                }
                else if (allCards[i] == 't') {
                    starshaiaKarta = starshaiaKarta + 14;
                }
                else {
                    starshaiaKarta = starshaiaKarta + (int)(allCards[i] - 48);
                }
                check++;
                if (check >= 5) {
                    fleshPosition = i - 5 * check;
                }
                if (allCards[i + 1] != ' ' && allCards[i + 2] != ' ' && allCards[i + 3] != ' ' && allCards[i + 4] != ' ') {
                    kapePosition = i;
                }
            }
            else {
                check = 0;
            }
        }
        if (fleshPosition != -1 && checkSuit(&allCards, fleshPosition)) {
            *myScore = 1000000000 + (fleshPosition + 1) + starshaiaKarta;
            return;
        }
        if (kapePosition != -1) {
            *myScore = 100000000 + kapePosition + starshaiaKarta;
            return;
        }
        int triplePosition = -1;
        int firstPairPosition = -1;
        int secondPairPosition = -1;
        for (int i = 0; i < 70; i = i + 5) {
            if (allCards[i] != ' ') {
                int cont = 0;
                for (int j = 1; j < 5; j++) {
                    if (allCards[i + j] != ' ') {
                        cont++;
                    }
                }
                if (cont == 3) {
                    triplePosition = i;
                }
                else if (cont == 2 && firstPairPosition == -1) {
                    firstPairPosition = i;
                }
                else if (cont == 2 && firstPairPosition != -1) {
                    secondPairPosition = i;
                }
            }
        }
        if (triplePosition != -1 && firstPairPosition != -1) {
            *myScore = 10000000 + (triplePosition + 1) + 1000 + (firstPairPosition + 1) + starshaiaKarta;
            return;
        }
        int heartCont = 0;
        int boobyCont = 0;
        int peaksCont = 0;
        int crossCont = 0;
        int costOfCards = 0;
        for (int i = 0; i < 70; i = i + 5) {
            if (allCards[i] != ' ') {
                if (allCards[i + 1] != ' ') {
                    boobyCont++;
                    costOfCards = costOfCards + (int)allCards[i];
                }
                if (allCards[i + 2] != ' ') {
                    heartCont++;
                    costOfCards = costOfCards + (int)allCards[i];
                }
                if (allCards[i + 3] != ' ') {
                    crossCont++;
                    costOfCards = costOfCards + (int)allCards[i];
                }
                if (allCards[i + 4] != ' ') {
                    peaksCont++;
                    costOfCards = costOfCards + (int)allCards[i];
                }
            }
        }
        if (heartCont == 5 || boobyCont == 5 || peaksCont == 5 || crossCont == 5) {
            *myScore = 1000000 + costOfCards + starshaiaKarta;
            return;
        }
        if (fleshPosition != -1) {
            *myScore = 100000 + fleshPosition + starshaiaKarta;
            return;
        }
        if (triplePosition != -1) {
            *myScore = 10000 + triplePosition + starshaiaKarta;
            return;
        }
        if (firstPairPosition != -1 && secondPairPosition != -1) {
            *myScore = 1000 + firstPairPosition + secondPairPosition + starshaiaKarta;
            return;
        }
        if (firstPairPosition != -1 && secondPairPosition == -1) {
            *myScore = 100 + firstPairPosition + starshaiaKarta;
            return;
        }
        *myScore = starshaiaKarta;
        return;
    }
    else {
        gotoxy(0, 1);
        cout << serverMsg;
    }
}



void game(SOCKET Connection, gamers* myData) {
    char serverMsg[256];
    char myMessage[2];
    recv(Connection, serverMsg, sizeof(serverMsg), NULL);
    if (serverMsg[0] == 'A') {
        std::cout << serverMsg;
        system("pause");
        myMessage[0] = 'Y';
        send(Connection, myMessage, sizeof(myMessage), NULL);
    }
    else {
        std::cout << "Sorry, something went wrong";
        return;
    }
    recv(Connection, serverMsg, sizeof(serverMsg), NULL);
    std::cout << serverMsg;

    int myEnemiesNumber = 0;
    int myTurn = 0;
    char myCard1[2];
    char myCard2[2];
    int tempNum = 0;
    myCard1[0] = serverMsg[tempNum];
    tempNum++;
    myCard1[1] = serverMsg[tempNum];
    tempNum = tempNum + 2;
    myCard2[0] = serverMsg[tempNum];
    tempNum++;
    myCard2[1] = serverMsg[tempNum];
    tempNum = tempNum + 2;
    myEnemiesNumber = serverMsg[tempNum];
    tempNum = tempNum + 2;
    myTurn = serverMsg[tempNum];
    for (int j = 0; j < myEnemiesNumber; j++) {
        tempNum = tempNum + 2;
        //ОТЛАДЬ!!!

        for (int i = 0; i < 4; i++) {
            if (serverMsg[tempNum] > 47 && serverMsg[tempNum] < 58) {
                myEnemies[j].sizeOfMoney++;
            }
            tempNum++;
        }
        tempNum = tempNum - 4;
        for (int i = myEnemies[j].sizeOfMoney; i > 0; i--) {
            myEnemies[j].money = myEnemies[j].money + (serverMsg[tempNum] - 48) * pow(10, i - 1);
            tempNum++;
        }
        tempNum = tempNum + 4;


        for (int i = 0; i < 2; i++) {
            if (serverMsg[tempNum] > 47 && serverMsg[tempNum] < 58) {
                myEnemies[j].sizeOfWinCount++;
            }
            tempNum++;
        }
        tempNum = tempNum - 2;
        for (int i = myEnemies[j].sizeOfWinCount; i > 0; i--) {
            myEnemies[j].winCount = myEnemies[j].winCount + (serverMsg[tempNum] - 48) * pow(10, i - 1);
            tempNum++;
        }
        tempNum = tempNum + 1;


        for (int i = 0; i < 2; i++) {
            if (serverMsg[tempNum] > 47 && serverMsg[tempNum] < 58) {
                myEnemies[j].sizeOfLoseCount++;
            }
            tempNum++;
        }
        tempNum = tempNum - 2;
        for (int i = myEnemies[j].sizeOfLoseCount; i > 0; i--) {
            myEnemies[j].loseCount = myEnemies[j].loseCount + (serverMsg[tempNum] - 48) * pow(10, i - 1);
            tempNum++;
        }
        tempNum = tempNum + 1;


        while (serverMsg[tempNum] != ' ') {
            myEnemies[j].sizeOfNickname++;
            tempNum++;
        }
        tempNum = tempNum - myEnemies[j].sizeOfNickname;
        for (int i = 0; i < myEnemies[j].sizeOfNickname; i++) {
            myEnemies[j].nickname[i] = serverMsg[tempNum];
            tempNum++;
        }
        tempNum--;
    }
    //проверка вывода данных
    /*std::cout << "\n" << myCard1[0] << myCard1[1] << " " << myCard2[0] << myCard2[1] << " " << myEnemiesNumber << "\n";
    for (int i = 0; i < myEnemiesNumber; i++) {
        cout << myEnemies[i].sizeOfNickname << " ";
        for (int y = 0; y < myEnemies[i].sizeOfNickname; y++) {
            std::cout << myEnemies[i].nickname[y];
        }
        cout << " " << myEnemies[i].sizeOfMoney << " " << myEnemies[i].money << " " << myEnemies[i].sizeOfWinCount << " " << myEnemies[i].winCount << " " << myEnemies[i].sizeOfLoseCount << " " << myEnemies[i].loseCount << "\n";
    }
    system("pause");*/
    send(Connection, myMessage, sizeof(myMessage), NULL);
    bool gameIsGoing = true;
    int maxBet = 10;
    int round = 1;
    int yourBet = 0;
    string cardOnTable1;
    string cardOnTable2;
    string cardOnTable3;
    string cardOnTable4;
    string cardOnTable5;
    int myScore = 0;
    system("cls");
    gamePlayScreen(myData, myCard1[0], myCard1[1], myCard2[0], myCard2[1], myEnemiesNumber, myTurn, maxBet, round, cardOnTable1, cardOnTable2, cardOnTable3, cardOnTable4, cardOnTable5);
    while (gameIsGoing) {
        recv(Connection, serverMsg, sizeof(serverMsg), NULL);
        system("cls");
        gamePlayScreen(myData, myCard1[0], myCard1[1], myCard2[0], myCard2[1], myEnemiesNumber, myTurn, maxBet, round, cardOnTable1, cardOnTable2, cardOnTable3, cardOnTable4, cardOnTable5);
        proverkaMsg(serverMsg, &maxBet, &yourBet, myData, Connection, &round, &cardOnTable1, &cardOnTable2, &cardOnTable3, &cardOnTable4, &cardOnTable5, myCard1[0], myCard1[1], myCard2[0], myCard2[1], &myScore);
        if (serverMsg[0] == 'a') {
            std::string otvet = std::to_string(myScore);
            recv(Connection, serverMsg, sizeof(serverMsg), NULL);
            char* otve = new char[otvet.size() + 1];
            strcpy(otve, otvet.c_str());
            send(Connection, otve, 256, NULL);
            recv(Connection, serverMsg, sizeof(serverMsg), NULL);
            gotoxy(0, 1);
            cout << "                                  ";
            gotoxy(0, 1);
            cout << serverMsg;
            gameIsGoing = false;
        }
        gamePlayScreen(myData, myCard1[0], myCard1[1], myCard2[0], myCard2[1], myEnemiesNumber, myTurn, maxBet, round, cardOnTable1, cardOnTable2, cardOnTable3, cardOnTable4, cardOnTable5);
    }
    Sleep(5000);
    gotoxy(0, 31);
    system("pause");
}

void game1(SOCKET Connection, gamers* myData) {
    char serverMsg[256];
    char myMessage[2];
    system("pause");
    myMessage[0] = 'Y';
    send(Connection, myMessage, sizeof(myMessage), NULL);
    recv(Connection, serverMsg, sizeof(serverMsg), NULL);
    cout << serverMsg;

    int myEnemiesNumber = 0;
    int myTurn = 0;
    char myCard1[2];
    char myCard2[2];
    int tempNum = 0;
    myCard1[0] = serverMsg[tempNum];
    tempNum++;
    myCard1[1] = serverMsg[tempNum];
    tempNum = tempNum + 2;
    myCard2[0] = serverMsg[tempNum];
    tempNum++;
    myCard2[1] = serverMsg[tempNum];
    tempNum = tempNum + 2;
    myEnemiesNumber = serverMsg[tempNum];
    tempNum = tempNum + 2;
    myTurn = serverMsg[tempNum];
    for (int j = 0; j < myEnemiesNumber; j++) {
        tempNum = tempNum + 2;


        for (int i = 0; i < 4; i++) {
            if (serverMsg[tempNum] > 47 && serverMsg[tempNum] < 58) {
                myEnemies[j].sizeOfMoney++;
            }
            tempNum++;
        }
        tempNum = tempNum - 4;
        for (int i = myEnemies[j].sizeOfMoney; i > 0; i--) {
            myEnemies[j].money = myEnemies[j].money + (serverMsg[tempNum] - 48) * pow(10, i - 1);
            tempNum++;
        }
        tempNum = tempNum + 4;


        for (int i = 0; i < 2; i++) {
            if (serverMsg[tempNum] > 47 && serverMsg[tempNum] < 58) {
                myEnemies[j].sizeOfWinCount++;
            }
            tempNum++;
        }
        tempNum = tempNum - 2;
        for (int i = myEnemies[j].sizeOfWinCount; i > 0; i--) {
            myEnemies[j].winCount = myEnemies[j].winCount + (serverMsg[tempNum] - 48) * pow(10, i - 1);
            tempNum++;
        }
        tempNum = tempNum + 1;


        for (int i = 0; i < 2; i++) {
            if (serverMsg[tempNum] > 47 && serverMsg[tempNum] < 58) {
                myEnemies[j].sizeOfLoseCount++;
            }
            tempNum++;
        }
        tempNum = tempNum - 2;
        for (int i = myEnemies[j].sizeOfLoseCount; i > 0; i--) {
            myEnemies[j].loseCount = myEnemies[j].loseCount + (serverMsg[tempNum] - 48) * pow(10, i - 1);
            tempNum++;
        }
        tempNum = tempNum + 1;


        while (serverMsg[tempNum] != ' ') {
            myEnemies[j].sizeOfNickname++;
            tempNum++;
        }
        tempNum = tempNum - myEnemies[j].sizeOfNickname;
        for (int i = 0; i < myEnemies[j].sizeOfNickname; i++) {
            myEnemies[j].nickname[i] = serverMsg[tempNum];
            tempNum++;
        }
        tempNum--;
    }
    //проверка вывода данных
    /*std::cout << "\n" << myCard1[0] << myCard1[1] << " " << myCard2[0] << myCard2[1] << " " << myEnemiesNumber << "\n";
    for (int i = 0; i < myEnemiesNumber; i++) {
        cout << myEnemies[i].sizeOfNickname << " ";
        for (int y = 0; y < myEnemies[i].sizeOfNickname; y++) {
            std::cout << myEnemies[i].nickname[y];
        }
        cout << " " << myEnemies[i].sizeOfMoney << " " << myEnemies[i].money << " " << myEnemies[i].sizeOfWinCount << " " << myEnemies[i].winCount << " " << myEnemies[i].sizeOfLoseCount << " " << myEnemies[i].loseCount << "\n";
    }
    system("pause");*/
    send(Connection, myMessage, sizeof(myMessage), NULL);
    bool gameIsGoing = true;
    int maxBet = 10;
    int round = 1;
    int yourBet = 0;
    string cardOnTable1;
    string cardOnTable2;
    string cardOnTable3;
    string cardOnTable4;
    string cardOnTable5;
    int myScore = 0;
    system("cls");
    gamePlayScreen(myData, myCard1[0], myCard1[1], myCard2[0], myCard2[1], myEnemiesNumber, myTurn, maxBet, round, cardOnTable1, cardOnTable2, cardOnTable3, cardOnTable4, cardOnTable5);
    while (gameIsGoing) {
        recv(Connection, serverMsg, sizeof(serverMsg), NULL);
        system("cls");
        gamePlayScreen(myData, myCard1[0], myCard1[1], myCard2[0], myCard2[1], myEnemiesNumber, myTurn, maxBet, round, cardOnTable1, cardOnTable2, cardOnTable3, cardOnTable4, cardOnTable5);
        proverkaMsg(serverMsg, &maxBet, &yourBet, myData, Connection, &round, &cardOnTable1, &cardOnTable2, &cardOnTable3, &cardOnTable4, &cardOnTable5, myCard1[0], myCard1[1], myCard2[0], myCard2[1], &myScore);
        if (serverMsg[0] == 'a') {
            std::string otvet = std::to_string(myScore);
            recv(Connection, serverMsg, sizeof(serverMsg), NULL);
            char* otve = new char[otvet.size() + 1];
            strcpy(otve, otvet.c_str());
            send(Connection, otve, 256, NULL);
            recv(Connection, serverMsg, sizeof(serverMsg), NULL);
            gotoxy(0, 1);
            cout << serverMsg;
            gameIsGoing = false;
        }
        gamePlayScreen(myData, myCard1[0], myCard1[1], myCard2[0], myCard2[1], myEnemiesNumber, myTurn, maxBet, round, cardOnTable1, cardOnTable2, cardOnTable3, cardOnTable4, cardOnTable5);
    }
    Sleep(5000);
    gotoxy(0, 31);
    system("pause");
}

int main(int argc, char* argv[])
{
    char nickname[15];
    char password[15];
    gamers myData;
    int tNum = 0;
    std::cout << "Input your nickname(max length is 13, only on english): ";
    std::cin.getline(nickname, sizeof(nickname));

    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "Error with wsaData\n" << std::endl;
        return 1;
    }

    SOCKADDR_IN addres;
    int sizeOfAddres = sizeof(addres);
    //параметр запуска сервера через пробел, ip-адрес машины
    std::string myIP;
    std::cout << "Input IP or press '!' and then ENTER: ";
    std::cin >> myIP;
    if (myIP[0] != '!')
    {
        char* mIP = new char[myIP.size() + 1];
        strcpy(mIP, myIP.c_str());
        addres.sin_addr.s_addr = inet_addr(mIP);
    }
    else
    {
        addres.sin_addr.s_addr = inet_addr("192.168.0.101");//меняй при каждом запуске компа
    }


    addres.sin_port = htons(1337);
    addres.sin_family = AF_INET;

    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR*)&addres, sizeof(addres)) != 0) {
        std::cout << "Error: failde connection to server.\n";
        return 1;
    }
    Sleep(500);
    send(Connection, nickname, sizeof(nickname), NULL);
    char serverMsg[256];
    recv(Connection, serverMsg, sizeof(serverMsg), NULL);
    std::cout << serverMsg;
    std::cin.getline(password, sizeof(password));
    send(Connection, password, sizeof(password), NULL);

    recv(Connection, serverMsg, sizeof(serverMsg), NULL);
    for (int i = 0; i < 4; i++) {
        if (serverMsg[tNum] > 47 && serverMsg[tNum] < 58) {
            myData.sizeOfMoney++;
        }
        tNum++;
    }
    tNum = tNum - 4;
    for (int i = myData.sizeOfMoney; i > 0; i--) {
        myData.money = myData.money + (serverMsg[tNum] - 48) * pow(10, i - 1);
        tNum++;
    }
    tNum = tNum + 4;


    for (int i = 0; i < 2; i++) {
        if (serverMsg[tNum] > 47 && serverMsg[tNum] < 58) {
            myData.sizeOfWinCount++;
        }
        tNum++;
    }
    tNum = tNum - 2;
    for (int i = myData.sizeOfWinCount; i > 0; i--) {
        myData.winCount = myData.winCount + (serverMsg[tNum] - 48) * pow(10, i - 1);
        tNum++;
    }
    tNum = tNum + 1;


    for (int i = 0; i < 2; i++) {
        if (serverMsg[tNum] > 47 && serverMsg[tNum] < 58) {
            myData.sizeOfLoseCount++;
        }
        tNum++;
    }
    tNum = tNum - 2;
    for (int i = myData.sizeOfLoseCount; i > 0; i--) {
        myData.loseCount = myData.loseCount + (serverMsg[tNum] - 48) * pow(10, i - 1);
        tNum++;
    }
    tNum = tNum + 1;

    gameStartScreen();
    recv(Connection, serverMsg, sizeof(serverMsg), NULL);

    if (serverMsg[0] == 'A') {
        std::cout << serverMsg;
        game1(Connection, &myData);
    }
    else {
        std::cout << serverMsg << "\n";
        game(Connection, &myData);
    }


    return 0;
}
