#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;

int main(){
    // русский
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");

    // 1 задание
    // вывод таблицы
    for(int i = 0;i<16;i++){
        cout<<(char)(192+i)<<" = "<<192+i;
        cout<<"\t\t"<<(char)(192+i+16)<<" = "<<192+i+16;
        cout<<"\t\t"<<(char)(192+i+32)<<" = "<<192+i+32;
        cout<<"\t\t"<<(char)(192+i+48)<<" = "<<192+i+48<<endl;
    }
    cout<<(char)(168)<<" = 168\t\t"<<(char)(184)<<" = 184"<<endl;

    char alf[] = "йцукенгшщзхъфывапролджэ€чсмитьбюЄ";//дл€ 1 допа
    char arr[] = "бвгджзйклмнпрстфхцчшщ"; //лишние символы
    char arr2[] = "бвгджзйклмнпрстфхцчшщЅ¬√ƒ∆«… ЋћЌ–ѕ—“‘’÷„Ўў";//-----------------------unsigned char
    char str[] = "ѕроверка –аЅо“о—пќсќбЌо—т»";
    char str_tmp[100] = ""; //строка-ответ
    int i = 0; 
    int i_tmp = 0;
    if(str[0]=='\0'){
        cout<<"¬ведите строку: ";
        cin>>str;
    }
    cout<<str<<" --> "; //вывод измен€емой строки
    while(str[i] != '\0'){ //поиск согласных
        bool fl = false;
        int len = 0;
        while(arr2[len] != '\0'){
            //cout<<"num: " << i << " corr: " << (char)tolower(str[i]) << " uncorr: " << (char)(((int)str[i]) + 32) << " num uncorr: "<< str[i] + 32 << endl;// проверка
            char simvB = (str[i]); //(ј -> а)
            if(arr2[len] == simvB) //если согл
                fl = true;
            len += 1;
        }
        if(!fl){
            str_tmp[i_tmp] = str[i];
            i_tmp++; //идЄм дальше
        }
        i += 1;
    }
    cout<<str_tmp<<endl;
    // 2 задание
    int N ;
    string check_ch; //буквы проверки
    bool dopdop = false;//-доп допа-
    string iskl;

    ifstream in("input.txt");//кол-во слов
    if(!in.is_open()){
        cout<<"input not found\n"<<"введите кол-во букв и буквы"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"\nбуквы: ";
        cin>>check_ch;
        if(N >10 || N <1){
            cout<<"\nWRONG N";
            return 1;
        }
    } else { //файл есть
        in>>N;
        in>>check_ch;
        int j = 0;
        in >> iskl;
        while (iskl[j] != '\0') {
            iskl[j] = tolower(iskl[j]);// (ј -> а)
            j++;
        }
        j = 0;
        while(check_ch[j] != '\0'){
            check_ch[j] = tolower(check_ch[j]);// (ј -> а)
            j++;
        }
        cout<<endl<<"N = "<<N<<endl;
        cout<<"ѕровер€емые буквы = "<<check_ch<<endl;
        in.close();
    }

    ifstream txt("text.txt"); //открытие
    if(!txt.is_open()){
        cout<<"“≈ —“ј Ќ≈“";
        return 1;
    } else {
        string words[10]; //массив слов
        string word; //слово из текста
        string znaki(".,:?-();!\"'"); // символы
        int check_size = check_ch.length(); // кол-во лишних символов
        i = 0; //номер слова в массиве слов

        while(!txt.eof()){
            txt>>word;
            for(int j = 0;j<size(word);j++){
                word[j] = tolower(word[j]); // (ј -> а)
            }
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            bool znl = true;//знак слева есть
            bool znr = true;//справа
            while (znr or znl) {
                if (znaki.find(word[0]) != string::npos) {
                    word.erase(0, 1);
                }
                else znl = false;
                if (znaki.find(word[size(word) - 1]) != string::npos) {
                    word.erase(size(word) - 1, 1);
                }
                else znr = false;
            }
            //for (int zero = 0; zero < 2; zero++) {//-------------------------------while
            //    if(znaki.find(word[0]) != string::npos){
            //        word.erase(0,1);
            //    }
            //    if(znaki.find(word[size(word)-1]) != string::npos){
            //        word.erase(size(word)-1,1);
            //    }
            //}
            bool fl = true;
            for(int j=0;j<word.length();j++){ 
                if(check_ch.find(word[j]) != string::npos){ //есть ли буква в лишних
                    fl = false;
                }
            }
            if(fl or word==iskl){ //слово подходит
                if (fl and word == iskl) {
                    continue;
                }
                if(i < N){ //не перешли предел
                    if(end(words) == find(begin(words),end(words),word)){ //нет в массиве -> добавл€ем
                        words[i] = word;
                        i++;
                    }
                } else { //перешли предел
                    bool fl1 = true;
                    while(fl1){
                        fl1 = false;
                        for(int a = 0;a<N;a++){ //сортировка пузырьком
                            if(size(words[a]) < size(words[a+1])){
                                swap(words[a],words[a+1]);
                                fl1 = true;
                            }
                        } 
                    }
                    for(int j = 0;j<N;j++){ 
                        if(size(words[j]) > size(word)) //сравнение длин
                            if(end(words) == find(begin(words),end(words),word)){ //нет в массиве -> добавл€ем (пустота = пустота)
                                words[j] = word;
                                break;
                        }
                    }
                }
            }
        }
        bool fl1 = true; //сортировка по убыванию
        while(fl1){
            fl1 = false;
            for(int a = 1;a<N;a++){
                if(size(words[a]) > size(words[a-1])){
                    swap(words[a],words[a-1]);
                    fl1 = true;
                }
            } 
        }
        ofstream out("result.txt");
        for(int i = 0;i<N;i++){
            cout<<words[i]<<" ";
            out<<words[i]<<" ";
        }
        out.close();
    }
    txt.close();

    // 1 доп ----------------------------------------------------обратна€ кодировка
    cout << "\n1 доп" << endl;
    ifstream cod("cod.txt");
    if (!cod.is_open()) {
        cout << "\ncod.txt not found" << endl;
        return 1;
    }
    else {
        string comb;
        char buk;
        string num_s;
        int num;
        string fin;

        bool andt = false;//дл€ проверки реверса

        while (!cod.eof()) {//если читаетс€
            cod >> comb;//comb - 1 слово
            if (comb == "") {
                cout << "!!!неправильные значени€!!!";
                return 1;
            }
            buk = comb[comb.length() - 1];//buk - слово без последнего символа
            if(!andt){
                for (i = 0; i < 33; i++) {//часть проверки на реверс
                    if (buk == alf[i]) {
                        andt = true;
                        break;
                    }
                }
            }
            if (comb.length() == 2 and andt) {//обычный случай
                num_s = comb.substr(0, comb.length() - 1);
                num = atoi(num_s.c_str());
                fin += " " + string(num, buk);//умножение*
            }
            else {//реверс
                fin += (" " + to_string(comb.length()) + comb[0]);
            } 
        }
        cout << fin;
        ofstream out("cod.txt");
        out << fin;
        out.close();
    }

    return 0;
}