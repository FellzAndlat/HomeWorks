#include <iostream>
#include <Windows.h>
#define MODE 1
#ifndef MODE
#error Необходимо определить метод
#endif

void add() {
	int num1, num2;
	std::cout << "Введите число 1: ";
	std::cin >> num1;
	std::cout << "Введите число 2: ";
	std::cin >> num2;
	std::cout << "Результат сложения: " << num1 + num2;
}

int main(){
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#if MODE == 1
	std::cout << "Работаю в боевом режиме" << '\n';
	add();
#elif MODE == 0
	std::cout << "Работаю в режиме тренировки";
#else 
	std::cout << "Неизвестный режим. Завершение работы";
#endif

	return 0;

}
