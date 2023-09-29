#include <iostream>
int main()
{
	setlocale(LC_ALL, "Russian");
		//unsigned char X = 7;
		// 7 = 00000111
		unsigned char X = 98; 
		// 98 = 01100010
		//unsigned char X = 241; 
		// 241 = 11110001
	std::cout << "¬ведите индекс i (от 1 до 8): ";
	unsigned short i;
	std::cin >> i;

	unsigned short ind_i;
	ind_i = ((X << (8 - i)) >> 7);

	std::cout << ind_i;

	//std::cout << "¬ведите индекс j (от 1 до 8): ";
	//unsigned short j;
	//unsigned short ind_j;
	//ind_j = ((X << (8 - i)) >> 7);
	
	//unsigned char num_i = ind_i;
	//unsigned char num_j = ind_j;
	//num_i = num_i << (8 - i);
	//std::cout << num_i;

	return 0;
}