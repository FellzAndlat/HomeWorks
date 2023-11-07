#include <cmath>
int addition(int num1, int num2) {
	int num3 = num1 + num2;
	return num3;
}
int subtraction(int num1, int num2) {
	int num3 = num1 - num2;
	return num3;
}
int multiplication(int num1, int num2) {
	int num3 = num1 * num2;
	return num3;
}
double division(int num1, int num2) {
	double num3 = static_cast<double>(num1) / static_cast<double>(num2);
	return num3;
}
int degree(int num1, int num2) {
	double num3 = pow(num1, num2);
	return num3;
}