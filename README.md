# Курсовая на тему "Сетевой покер"
# Выполнил студент группы 0091 Курилов Роман

# Введение
Целью данной работы является создание сетевой игры в покер от 2-х до 6 игроков. Разработанные программы под системы Windows.

# Постановка задачи
Задачей данной курсовой работы является разработка параллельного приложения сервера и приложения клиента, которые будут обмениваться информацией по ходу игры. Приложение сервера использует многопоточность для подключения игроков и синхронизации их действий, а остальные действия выполняются в одном главном потоке. Приложение клиента работает только на главном потоке. Игра должна работать под управлением операционной системы семейства Windows 10/7. 
Игра будет иметь графический интерфейс, нарисованный символами ascii. В приложении будет реализовано простое подключение игрока к серверу, анимированная заставка, игровой интерфейс. Приложение сервера будет лишь спрашивать кол-во игроков, участвующих в игре, и выводить строчки информации, которые отправляет клиентам.

# Алгоритм работы программы
Правила игры следующие. В одной игре может принимать участие от двух до шести игроков и человек, на компьютере которого запущен сервер(конечно, приложение сервера может быть запущенно на компьютере какого-нибудь игрока). Вначале запускается приложение сервера. При запуске оно спрашивает ip, на котором будет работать. Для этого запускаем командную строку(cmd), вводим команду ipconfig, находим "Адаптер Ethernet Ethernet", а в нём поле "IPv4-адрес". Это и есть наш ip, который нужно ввести. Можно конешно ввести символ '!' и нажать 'enter'. Тогда сервер будет использовать ip поумолчанию(но очень сомневаюсь, что он будет схожим с вашим, т.к. в таком случае сервер не заработает). После ip нас попросят ввести кол-во игроков. Вводим число игроков и сервер выдаёт нам сообщение "i am ready", что означает, что можно подключать игроков.
При запуске приложения клиента

