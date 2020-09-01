#include <iostream>
#include <fstream>
#include <string>

// Создание файла
void create()
{
	std::ofstream outfile("input.txt");
	outfile << "12345678";
	outfile.close();
}

// Чтение из файла
std::string read() {
	std::ifstream infile("input.txt");
	std::string line;
	std::getline(infile, line);
	infile.close();
	return (line);
}

// Сумма цифр числа
void first_task() {
	std::string num = read();

	std::cout << "First task answer: sum of " << num << " is ";

	int sum = 0;

	while (num.length() > 0) {
		sum += num.front() - '0';
		num = num.substr(1, num.length() - 1);
	}

	std::cout << sum << std::endl;
	std::cout << std::endl;
}

// Бинарный поиск
void second_task(int a, int arr[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (high - low) / 2 + low;
		if (a < arr[mid])
			high = mid - 1;
		else if (a > arr[mid])
			low = mid + 1;
		else {
			std::cout << "Second task answer: element has " << mid << " index.";
			std::cout << std::endl;
			return;
		}
	}
	std::cout << "but nobody came";
	std::cout << std::endl;
}

void third_task(int arr[], int n) {
	std::cout << std:: endl << "Third task answer. Bubble sort of array: ";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}

	std::cout << "Will be: ";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

// a = A, b = B => a = B, b = A
void fourth_task() {
	int a, b;
	std::cout << std::endl << "Input a and b: " << std::endl;
	std::cin >> a;
	std::cin >> b;

	std::cout << "Reverse for a: " << a << " and b: " << b;

	a = a + b;
	b = a - b;
	a = a - b;

	std::cout << " will be a: " << a << " and b: " << b;
	std::cout << std::endl;
}

// Произведение факториалов за один цикл
void fifth_task(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++) {
		fact *= pow(i, n - i + 1);
	}
	std::cout << std::endl << "Multiplication of factorials for " << n << " will be " << fact;
}

int main()
{
	create();

	first_task();

	int arr[8] = { 2, 11, 12, 15, 21, 45, 90, 100 };
	second_task(21, arr, 8);

	int arr_unsort[9] = { 33, 5, 99, -1, 0, 100, 10000, 38, 32000 };
	third_task(arr_unsort, 9);

	fourth_task();

	fifth_task(5);

	return 0;
}