//#include<iostream>
//#include<fstream>
//#include<string>
//#include<algorithm>
///*  1.	Дана строка длиной не более 100 символов.Удалить в ней все согласные буквы.Другие символы изменять не нужно.
//2.	Дан файл, содержащий русский текст.Найти в тексте N(N ≤ 10) самых длинных слов, не содержащих ни одной
//буквы из заданного слова.Записать найденные слова в текстовый файл в порядке не возрастания длины.
//Все найденные слова должны быть разными*/
//int main() {
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    //использование кириллицы
    system("chcp 1251");
    setlocale(LC_ALL, "RUSSIAN");

    //      задание 1

    //таблица
    for (int i = 0; i < 16; i++) {
        cout << (char)(192 + i) << " = " << 192 + i;
        cout << "\t\t" << (char)(192 + i + 16) << " = " << 192 + i + 16;
        cout << "\t\t" << (char)(192 + i + 32) << " = " << 192 + i + 32;
        cout << "\t\t" << (char)(192 + i + 48) << " = " << 192 + i + 48 << endl;
    }
    cout << (char)(168) << " = 168\t\t" << (char)(184) << " = 184" << endl;
    char arr[] = "цкнгшщзхфвпрлджчсмтб";
    char str[100] = "Это Тестовая Строка";
    int i = 0;
    if (str[0] == '\0') {
        cout << "Введите строку: ";
        cin >> str;
    }
    cout << str << " --> ";
    while (str[i] != '\0') {
        bool fl = false;
        int len = 0;
        while (arr[len] != '\0') {
            char simvB = tolower(str[i]);
            if (arr[len] == simvB)
                fl = true;
            len += 1;
        }
        if (fl) {
            str[i] = ' ';
        }
        i += 1;
    }
    cout << str << endl;


    return 0;
}