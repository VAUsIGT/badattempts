#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");///*
	std::cout << "������� A: ";
	int a;
	std::cin >> a;
	std::cout << "������� B: ";
	int b;
	std::cin >> b;
	std::cout << "������� C: ";
	int c;
	std::cin >> c;

	// 1 �����
	if (a % b == 0) {
		if (a > b) { std::cout <<"A>B, "<<  (a / b + c); }
		else{ if (b < c) { std::cout <<"B<C, " << (a / b - c); } }
	}
	else { std::cout <<"A<B, B>C, " << (a + b) * c; }

	// 2 �����
	std::cout << "\n��� ������: ";
	unsigned short n;
	std::cin >> n;
	switch (n) {
	case 1:std::cout << "�����";
		break;
	case 25:std::cout << "�������";
		break;
	case 30:std::cout << "����� ������� �����������������";
		break;
	case 500:std::cout << "������";
		break;
	case 645:std::cout << "��������";
		break;
	case 1966:std::cout << "���������";
		break;
	case 4949:std::cout << "������� ������� ����������";
		break;
	default:std::cout << "�� ����� �� �������";
	}
	//*/
	// ��������������
	std::cout << "\n������� X (1 ��� -1): ";
	signed bool x;
	std::cin >> x;
	switch (x) {
	case 1:std::cout << "Positive number";
		break;
	case -1:std::cout << "Negative number";
	}
}