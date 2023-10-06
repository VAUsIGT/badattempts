#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");///*
	std::cout << "Введите A: ";
	int a;
	std::cin >> a;
	std::cout << "Введите B: ";
	int b;
	std::cin >> b;
	std::cout << "Введите C: ";
	int c;
	std::cin >> c;

	// 1 часть
	if (a % b == 0) {
		if (a > b) { std::cout <<"A>B, "<<  (a / b + c); }
		else{ if (b < c) { std::cout <<"B<C, " << (a / b - c); } }
	}
	else { std::cout <<"A<B, B>C, " << (a + b) * c; }

	// 2 часть
	std::cout << "\nКод товара: ";
	unsigned short n;
	std::cin >> n;
	switch (n) {
	case 1:std::cout << "Нефть";
		break;
	case 25:std::cout << "Авокадо";
		break;
	case 30:std::cout << "Сахар рафинад быстрорастворимый";
		break;
	case 500:std::cout << "Яблоки";
		break;
	case 645:std::cout << "Помидоры";
		break;
	case 1966:std::cout << "Апельсины";
		break;
	case 4949:std::cout << "Колбаса вареная докторская";
		break;
	default:std::cout << "Мы таким не торгуем";
	}
	//*/
	// Дополнительное
	std::cout << "\nВведите X (1 или -1): ";
	signed bool x;
	std::cin >> x;
	switch (x) {
	case 1:std::cout << "Positive number";
		break;
	case -1:std::cout << "Negative number";
	}
}