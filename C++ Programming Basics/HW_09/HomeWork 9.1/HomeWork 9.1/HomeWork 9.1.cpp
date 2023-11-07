#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	int get_n() {
		return numerator_;
	}
	int get_d() {
		return denominator_;
	}
	bool operator == (Fraction other) {
		return get_n() * other.get_d() == other.get_n() * get_d();
	}
	bool operator != (Fraction other) {
		return !(*this == other);
	}
	bool operator > (Fraction other) {
		return get_n()* other.get_d() > other.get_n() * get_d();
	}
	bool operator < (Fraction other) {
		return (other > *this);
	}
	bool operator <= (Fraction other) {
		return !(*this < other);
	}
	bool operator >= (Fraction other) {
		return !(*this > other);
	}
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
};

int main()
{
	Fraction f1(1, 2);
	Fraction f2(6, 10);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}