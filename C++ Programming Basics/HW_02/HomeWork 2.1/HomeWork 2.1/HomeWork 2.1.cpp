#include <iostream>

enum class months {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,	
};

void EnumerationOfMonths(int number) {
	months m = static_cast<months>(number);

	switch (m) {

	case months::January:
		std::cout << "������" << "\n";
		break;
	case months::February:
		std::cout << "�������" << "\n";
		break;
	case months::March:
		std::cout << "����" << "\n";
		break;
	case months::April:
		std::cout << "������" << "\n";
		break;
	case months::May:
		std::cout << "���" << "\n";
		break;
	case months::June:
		std::cout << "����" << "\n";
		break;
	case months::July:
		std::cout << "����" << "\n";
		break;
	case months::August:
		std::cout << "������" << "\n";
		break;
	case months::September:
		std::cout << "��������" << "\n";
		break;
	case months::October:
		std::cout << "�������" << "\n";
		break;
	case months::November:
		std::cout << "������" << "\n";
		break;
	case months::December:
		std::cout << "�������" << "\n";
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "");

	int number;

	for (;;) {
		std::cout << "������� ����� ������: ";
		std::cin >> number;
		if (number == 0) {
			std::cout << "����� �������";
			break;
		}
		else if (number > 12) {
			std::cout << "������������ �����, ������� ��������� ������ ������� :3" << "\n";
		}
		EnumerationOfMonths(number);
	}

	return 0;
}
