#include <iostream>

void EnumerationOfMonths(int number) {
	switch (number) {
	case 1:
		std::cout << "������" << "\n";
		break;
	case 2:
		std::cout << "�������" << "\n";
		break;
	case 3:
		std::cout << "����" << "\n";
		break;
	case 4:
		std::cout << "������" << "\n";
		break;
	case 5:
		std::cout << "���" << "\n";
		break;
	case 6:
		std::cout << "����" << "\n";
		break;
	case 7:
		std::cout << "����" << "\n";
		break;
	case 8:
		std::cout << "������" << "\n";
		break;
	case 9:
		std::cout << "��������" << "\n";
		break;
	case 10:
		std::cout << "�������" << "\n";
		break;
	case 11:
		std::cout << "������" << "\n";
		break;
	case 12:
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
