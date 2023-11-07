#include <iostream>
#include <Windows.h>
#include "Arithmetic.h"

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num1, num2, item;

	std::cout << "������� ������ �����: ";
	std::cin >> num1;
	std::cout << "������� ������ �����: ";
	std::cin >> num2;
	std::cout << "�������� �������� (1 - ��������, 2 - ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
	std::cin >> item;

	switch (item) {
	case 1:
		std::cout << num1 << " + " << num2 << " = " << addition(num1, num2);
		break;
	case 2:
		std::cout << num1 << " - " << num2 << " = " << subtraction(num1, num2);
		break;
	case 3:
		std::cout << num1 << " * " << num2 << " = " << multiplication(num1, num2);
		break;
	case 4:
		std::cout << num1 << " / " << num2 << " = " << division(num1, num2);
		break;
	case 5:
		std::cout << num1 << " � ������� " << num2 << " = " << degree(num1, num2);
		break;
	}
	return 0;
}