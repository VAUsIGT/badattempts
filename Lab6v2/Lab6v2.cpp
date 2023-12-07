#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main(){
    // �������
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");

    // 1 �������
    // ����� �������
    for(int i = 0;i<16;i++){
        cout<<(char)(192+i)<<" = "<<192+i;
        cout<<"\t\t"<<(char)(192+i+16)<<" = "<<192+i+16;
        cout<<"\t\t"<<(char)(192+i+32)<<" = "<<192+i+32;
        cout<<"\t\t"<<(char)(192+i+48)<<" = "<<192+i+48<<endl;
    }
    cout<<(char)(168)<<" = 168\t\t"<<(char)(184)<<" = 184"<<endl;

    char arr[] = "���������������������"; //������ �������
    char arr2[] = "������������������������������������������";
    char str[] = "�������� �����������������";
    char str_tmp[100] = ""; //������-�����
    int i = 0; 
    int i_tmp = 0;
    if(str[0]=='\0'){
        cout<<"������� ������: ";
        cin>>str;
    }
    cout<<str<<" --> "; //����� ���������� ������
    while(str[i] != '\0'){ //����� ���������
        bool fl = false;
        int len = 0;
        while(arr2[len] != '\0'){
            //cout<<"num: " << i << " corr: " << (char)tolower(str[i]) << " uncorr: " << (char)(((int)str[i]) + 32) << " num uncorr: "<< str[i] + 32 << endl;// ��������
            char simvB = (str[i]); //(� -> �)
            if(arr2[len] == simvB) //���� ����
                fl = true;
            len += 1;
        }
        if(!fl){
            str_tmp[i_tmp] = str[i];
            i_tmp++; //��� ������
        }
        i += 1;
    }
    cout<<str_tmp<<endl;
    // 2 �������
    int N ;
    string check_ch; //����� ��������

    ifstream in("input.txt");//���-�� ����
    if(!in.is_open()){
        cout<<"input not found"<<"������� ���-�� ���� � �����"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"�����: ";
        cin>>check_ch;
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
    } else { //���� ����
        in>>N;
        in>>check_ch;
        int j = 0;
        while(check_ch[j] != '\0'){
            check_ch[j] = tolower(check_ch[j]);// (� -> �)
            j++;
        }
        cout<<endl<<"N = "<<N<<endl;
        cout<<"����������� ����� = "<<check_ch<<endl;
        in.close();
    }

    ifstream txt("text.txt"); //��������
    if(!txt.is_open()){
        cout<<"������ ���";
        return 1;
    } else {
        string words[10]; //������ ����
        string word; //����� �� ������
        string znaki(".,:?-();!\"'"); // �������
        int check_size = check_ch.length(); // ���-�� ������ ��������
        i = 0; //����� ����� � ������� ����

        while(!txt.eof()){
            txt>>word;
            for(int j = 0;j<size(word);j++){
                word[j] = tolower(word[j]); // (� -> �)
            }
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            for (int zero = 0; zero < 2; zero++) {
                if(znaki.find(word[0]) != string::npos){
                    word.erase(0,1);
                }
                if(znaki.find(word[size(word)-1]) != string::npos){
                    word.erase(size(word)-1,1);
                }
            }
            bool fl = true;
            for(int j=0;j<word.length();j++){ 
                if(check_ch.find(word[j]) != string::npos){ //���� �� ����� � ������
                    fl = false;
                }
            }
            if(fl){ //����� ��������
                if(i < N){ //�� ������� ������
                    if(end(words) == find(begin(words),end(words),word)){ //��� � ������� -> ���������
                        words[i] = word;
                        i++;
                    }
                } else { //������� ������
                    bool fl1 = true;
                    while(fl1){
                        fl1 = false;
                        for(int a = 0;a<N;a++){ //���������� ���������
                            if(size(words[a]) < size(words[a+1])){
                                swap(words[a],words[a+1]);
                                fl1 = true;
                            }
                        } 
                    }
                    for(int j = 0;j<N;j++){ 
                        if(size(words[j]) > size(word)) //��������� ����
                            if(end(words) == find(begin(words),end(words),word)){ //��� � ������� -> ���������
                                words[j] = word;
                                break;
                        }
                    }
                }
            }
        }
        bool fl1 = true; //���������� �� ��������
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

    // 1 ��� 
    cout << "\n1 ���" << endl;
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
        while (!cod.eof()) {//���� ��������
            cod >> comb;//comb - 1 �����
            buk = comb[comb.length() - 1];//buk - ����� ��� ���������� �������
            num_s = comb.substr(0, comb.length() - 1);
            num = atoi(num_s.c_str());
            fin += string(num, buk) + " ";//���������*
        }
        cout << fin;
        ofstream out("cod.txt");
        out << fin;
        out.close();
    }
    return 0;
}
//������� ��� ����