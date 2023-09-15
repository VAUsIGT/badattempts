//int       // целое число (−2147483648 , 2147483647)
//long long // целое число  (−9223372036854775808 , 9223372036854775807)
//short     // целое число (–32768 до 32767)
//char      // один символ в кодировке ASCII (-128 , 127)
//float     // дробное число (3.4E-38 , 3.4E+38)
//преписка unsigned позволяет переменной хранить только числа в положительном диапазоне

#include <iostream>
#include <windows.h>

float main()
{
	setlocale(LC_ALL, "Russian");

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);

	std::cout << "Введите площадь основания:";
	float s;
	std::cin >> s;

	float h;
	std::cout << "Введите высоту:";
	std::cin >> h;


	float v = (s * h)/3;

	std::cout << "Объём пирамиды: ";
	std::cout << v;
	std::cout << "\nСпасибо за использование технологий VAUsIGT\n-------------------------------------------";
	return 0;
}