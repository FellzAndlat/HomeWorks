#include "Isosceles_triangle.h"

Isosceles_triangle::Isosceles_triangle(int a, int b, int A, int B) : Right_triangle(a, b, a, A, B) {
    this->C = A;
    name = "Равнобедренный треугольник: ";
}