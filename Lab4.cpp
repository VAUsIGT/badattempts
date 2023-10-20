/*
1.	���� ������������������ ����� ����� {A1, A2, �, AN}. ����� ����� ���� ������������� �����,
���������� �� ����� ����� � ���������� ��� ����������.
2.	���� ����� ����� X <10^9. ����� ���������� ����� �����.
*/
#include<iostream>
int main() {
    setlocale(LC_ALL, "Russian");
    //1 �����
    int num_number;                                        //���� ���-��
    std::cout << "������� ���������� ����: ";
    std::cin >> num_number;

    if (num_number < 1) {                                  //��������
        std::cout << "���� �� ����� ���� ������ �����";
        return 1;
    }

    int number;                                            //����� ������������������
    int sum = 0;
    int min_num = -2147483648;
    int ct = 0;


    std::cout << "������� �����\n";

    for (int i = 0; i != num_number; i++) {                //���� �����
        std::cout << i + 1 << ": ";
        std::cin >> number;


        if (number == min_num) {                           //���-�� ���. ��������
            ct++;
        }
        if (number < 0) {                                  //�������� ���������.
            sum += number;
            if (number > min_num) {
                min_num = number;
                ct = 1;                                    //����� ����. ���. ��������
            }
        }
    }
    if (sum != 0) {
        std::cout << "����� �������������: " << sum << std::endl;
        std::cout << "���������� �� �������������: " << min_num << std::endl;
        std::cout << "���-�� ��� ��������: " << ct << std::endl;
    }
    else{ std::cout << "������������� ����� ���" << std::endl; }
    
    //2 �����
    int max_x = 0;
    int x;
    std::cout << "������� X: ";
    std::cin >> x;
    x = abs(x);
    while (x!=0) {
        int digit = x % 10;
        if (digit > max_x) {
            max_x = digit;
        }
        x /= 10;
    }
    std::cout << "������������ �����: " << max_x << std::endl;
    return 0;
}