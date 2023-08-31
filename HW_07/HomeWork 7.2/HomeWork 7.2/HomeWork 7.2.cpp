#include <iostream>
#include <Windows.h>
#define SUB(a, b) a - b
#ifndef SUB
#error Необходимо определить метод
#endif

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a = 6;
	int b = 5; 
	int c = 2;

	std::cout << SUB(a, b) << '\n';
	std::cout << (SUB(a, b)) * c  << '\n';
	std::cout << (SUB(a, (b + c))) * c << '\n';

	return 0;
}
