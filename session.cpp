////2
//#include <iostream>
//using namespace std;
//int main()
//{
//	char x = 'a';
//	string a = "Galahad";
//	int l = a.length();
//	int i = 0;
//	while ((a[i] != x) and i<l-1) {
//		i++;
//	}
//	cout << i + 1;
//	return 0;
//}

////5
//#include<iostream>
//int main() {
//	setlocale(LC_ALL, "RUSSIAN");
//	char words[] = { "кот машина бегемот" };
//	std::string a = "кот машина бегемот";
//}

////8
//#include<iostream>
//int multy(int, int);
//double multy(double, double);
//int main(){
//	int i{multy(8, 6)};
//	std::cout << i << std::endl;
//	double j{ multy(3.6, 1.6) };
//	std::cout << j << std::endl;
//}
//int multy(int a, int b) {
//	return a * b;
//}
//double multy(double a, double b) {
//	return a * b;
//}

//9
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	int mass[5][5];
	int m = 4;
	int n = 4;
	cout << "введите числа" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mass[j][i];
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << endl;
		for (int j = 0; j < n; ++j) {
			cout << mass[i][j]<<" ";
		}
	}
	cout << "\nвыберите столбцы:" << endl;
	int left;
	int right;
	int mid = 0;
	cin >> left >> right;
	left-- and right--;
	if (abs(left) > m or abs(right) > m) {
		return 1;
	}
	for (int j = 0; j < n; ++j) {
		mid = mass[j][left];
		mass[j][left] = mass[j][right];
		mass[j][right] = mid;
	}
	cout << "новая таблица:" << endl;
	for (int i = 0; i < m; ++i) {
		cout << endl;
		for (int j = 0; j < n; ++j) {
			cout << mass[i][j] << " ";
		}
	}
}