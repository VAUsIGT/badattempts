/*
1.	Дана последовательность целых чисел {A1, A2, …, AN}. Найти сумму всех отрицательных чисел,
наибольшее из таких чисел и количество его повторений.
2.	Дано целое число X <10^9. Найти наибольшую цифру числа.
*/
#include<iostream>
#include<math.h>
int main() {
    setlocale(LC_ALL, "Russian");
    //1 часть
    int num_number;                                        //ввод кол-ва
    std::cout << "Введите количество цифр: ";
    std::cin >> num_number;

    if (num_number < 1) {                                  //проверка
        std::cout << "Цифр не может быть меньше одной";
        return 1;
    }

    int number;                                            //число последовательности
    int sum = 0;
    int min_num = -2147483648;
    int ct = 0;


    std::cout << "Введите числа\n";

    for (int i = 0; i != num_number; i++) {                //ввод числа
        std::cout << i + 1 << ": ";
        std::cin >> number;


        if (number == min_num) {                           //кол-во мин. повторов
            ct++;
        }
        if (number < 0) {                                  //проверка минимальн.
            sum += number;
            if (number > min_num) {
                min_num = number;
                ct = 1;                                    //сброс счет. мин. повторов
            }
        }
    }
    if (sum != 0) {
        std::cout << "Сумма отрицательных: " << sum << std::endl;
        std::cout << "Наибольшее из отрицательных: " << min_num << std::endl;
        std::cout << "Кол-во его повторов: " << ct << std::endl;
    }
    else{ std::cout << "Отрицательных чисел нет" << std::endl; }
    
    //2 часть
    int max_x = 0;
    int x;
    std::cout << "Введите X: ";
    std::cin >> x;
    if (x < pow(10, 9)) {
        x = abs(x);
        while (x != 0) {
            int digit = x % 10;
            if (digit > max_x) {
                max_x = digit;
            }
            x /= 10;
        }
        std::cout << "Максимальное цифра: " << max_x << std::endl;
    }
    else {
        std::cout << "Превышено макс. число" << std::endl;
    }
    return 0;
}
