#include <iostream>
#include <Windows.h>
#define MODE 1
#ifndef MODE
#error ���������� ���������� �����
#endif

void add() {
	int num1, num2;
	std::cout << "������� ����� 1: ";
	std::cin >> num1;
	std::cout << "������� ����� 2: ";
	std::cin >> num2;
	std::cout << "��������� ��������: " << num1 + num2;
}

int main(){
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#if MODE == 1
	std::cout << "������� � ������ ������" << '\n';
	add();
#elif MODE == 0
	std::cout << "������� � ������ ����������";
#else 
	std::cout << "����������� �����. ���������� ������";
#endif

	return 0;

}
