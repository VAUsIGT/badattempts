#include <iostream>

bool starts_with3(int n) {
	short m = 1;
	while (n != 0) {
		m = n % 10;
		n /= 10;
	}
	if (m == 3) return true;
	else return false;
}

int sum_digits(int n) {
	int sum = 0;
	while (n != 0) {
		sum += abs(n) % 10;
		n = abs(n) / 10;
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int const k = 19;
	int mas[k];
	int n;
	bool flag = false;
	std::cout << "Ââåäèòå äëèíó ïîñëåäîâàòåëüíîñòè: ";
	std::cin >> n;
	if ((n == 0) or (n > 19)) {
		std::cout << "Íåïðàâèëüíî, ïîïðîáóé. åù¸. ðàç.";
		return 1;
	}
	std::cout << "Ââåäèòå ÷èñëà" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cin >> mas[i];
	}
	for (int i = 0; i < n; i++) {
		if (starts_with3(mas[i])) {
			flag = true;
			break;
		}
	}
	if (flag)
		for (short a = 0; a < n; a++)
			for (short b = 0; b < n; b++)
				if (mas[b] > mas[a])
					std::swap(mas[a], mas[b]);
	for (int i = 0; i < n; i++) {
		std::cout << mas[i]<<" ";
	}
	std::cout << std::endl;

	//2 óñëîâèå
	const short M = 9;
	const short N = 9;
	int matrix[M][N];
	short a;
	short b;
	short count_max = SHRT_MIN;
	short count;
	std::cout << "Ââåäèòå ðàçìåð ìàòðèöû(M*N): " << std::endl;
	std::cin >> a >> b;
	std::cout << "Ââåäèòå ÷èñëà ìàòðèöû: " << std::endl;
	for (short i = 0; i < a; i++)
		for (short j = 0; j < b; j++)
			std::cin >> matrix[i][j];
	for (short j = 0; j < b; j++) {
		count = 0;
		for (short i = 0; i < a; i++)
			if (matrix[i][j] < 0)
				count += 1;
		if (count > count_max) count_max = count;
	}
	for (short j = 0; j < b; j++) {
		count = 0;
		for (short i = 0; i < a; i++)
			if (matrix[i][j] < 0)
				count += 1;
		if (count == count_max) {
			for (short i = 0; i < a; i++)
				matrix[i][j] = -1;
		};
	}
	std::cout << "Âàøà ìàòðèöà: " << std::endl;
	for (short i = 0; i < a; i++) {
		for (short j = 0; j < b; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
	
	// äîï
	std::cout << "äîï" << std::endl;
	if (flag)
		for (short a = 0; a < n; a++)
			for (short b = 0; b < n; b++)
				if (sum_digits(mas[b]) > sum_digits(mas[a]))
					std::swap(mas[a], mas[b]);
	for (int i = 0; i < n; i++) {
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
