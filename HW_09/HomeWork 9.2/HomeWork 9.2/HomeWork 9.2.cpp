#include <iostream>
#include <Windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction& operator ++ () {
		numerator_ += denominator_;
		return *this;
	}
	Fraction operator ++ (int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator -- () {
		numerator_ -= denominator_;
		denominator_;
		return *this;
	}
	Fraction operator -- (int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	Fraction operator + (Fraction other) {
		return Fraction(((numerator_ * other.get_d()) + (other.get_n() * denominator_)), (denominator_ * other.get_d()));
	}
	Fraction operator - (Fraction other) {
		return Fraction(((numerator_ * other.get_d()) - (other.get_n() * denominator_)), (denominator_ * other.get_d()));
	}
	Fraction operator * (Fraction other) {
		return Fraction((numerator_ * other.get_n()), (denominator_ * other.get_d()));
	}
	Fraction operator / (Fraction other) {
		return Fraction((numerator_ * other.get_d()), (denominator_ * other.get_n()));
	}
	int get_n() {
		int less;
		for (;;) {
			if (numerator_ < denominator_)                                 
				less = numerator_;
			else                                                  
				less = denominator_;
			for (int j = less; j > 0; j--) {                      
				if (!(numerator_ % j) && !(denominator_ % j)) {
					numerator_ /= j;
					denominator_ /= j;
					continue;
				}
				else if (j == 1) {
					break;
				}
			}
			break;
		}
		return numerator_;
	}
	int get_d() {
		int less;
		for (;;) {
			if (numerator_ < denominator_)
				less = numerator_;
			else
				less = denominator_;
			for (int j = less; j > 0; j--) {
				if (!(numerator_ % j) && !(denominator_ % j)) {
					numerator_ /= j;
					denominator_ /= j;
					continue;
				}
				else if (j == 1) {
					break;
				}
			}
			break;
		}
		return denominator_;
	}

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int numerator, denominator;
	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> numerator;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> denominator;
	Fraction f1(numerator, denominator);
	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> numerator;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> denominator;
	Fraction f2(numerator, denominator);
	Fraction sum = f1 + f2;
	Fraction sub = f1 - f2;
	Fraction mult = f1 * f2;
	Fraction div = f1 / f2;

	std::cout << f1.get_n() << "/" << f1.get_d() << " + " << f2.get_n() << "/" << f2.get_d() << " = " << sum.get_n() << "/" << sum.get_d() << std::endl;
	std::cout << f1.get_n() << "/" << f1.get_d() << " - " << f2.get_n() << "/" << f2.get_d() << " = " << sub.get_n() << "/" << sub.get_d() << std::endl;
	std::cout << f1.get_n() << "/" << f1.get_d() << " * " << f2.get_n() << "/" << f2.get_d() << " = " << mult.get_n() << "/" << mult.get_d() << std::endl;
	std::cout << f1.get_n() << "/" << f1.get_d() << " / " << f2.get_n() << "/" << f2.get_d() << " = " << div.get_n() << "/" << div.get_d() << std::endl;

	std::cout << "++" << f1.get_n() << "/" << f1.get_d() << " * " << f2.get_n() << "/" << f2.get_d() << " = ";

	Fraction mult2 = ++f1 * f2;

	std::cout << mult2.get_n() << "/" << mult2.get_d() << std::endl;
	std::cout << "«начение дроби 1 = " << f1.get_n() << "/" << f1.get_d() << std::endl;

	std::cout << f1.get_n() << "/" << f1.get_d() << "--" << " * " << f2.get_n() << "/" << f2.get_d() << " = ";
	Fraction mult3 = f1-- * f2;
	std::cout << mult3.get_n() << "/" << mult3.get_d() << std::endl;
	std::cout << "«начение дроби 1 = " << f1.get_n() << "/" << f1.get_d() << std::endl;
	
	return 0;
}