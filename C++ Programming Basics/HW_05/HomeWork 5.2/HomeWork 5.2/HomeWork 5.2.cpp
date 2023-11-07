#include <iostream>
#include <cstring>
#include <Windows.h>
#include <vector>

class Triangle {
protected:
    int a, b, c;
    int A, B, C;
    std::string name;
public:
    int get_a() {
        return a;
    }
    int get_b() {
        return b;
    }
    int get_c() {
        return c;
    }
    int get_A() {
        return A;
    }
    int get_B() {
        return B;
    }
    int get_C() {
        return C;
    }
    std::string get_name() {
        return name;
    }
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        name = "Треугольник: ";
    }
};

class Right_triangle :public Triangle {
public:
    Right_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник: ";
    }
};

class Isosceles_triangle :public Right_triangle {
public:
    Isosceles_triangle(int a, int b, int A, int B) : Right_triangle(a, b, a, A, B) {
        this->C = A;
        name = "Равнобедренный треугольник: ";
    }
};

class Equilateral_triangle :public Isosceles_triangle {
public:
    Equilateral_triangle(int a, int A) : Isosceles_triangle(a, a, A, A) {
        name = "Равносторонний треугольник: ";
    }
};

class Quadrilateral {
protected:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;
public:
    int get_a() {
        return a;
    }
    int get_b() {
        return b;
    }
    int get_c() {
        return c;
    }
    int ger_d() {
        return d;
    }
    int get_A() {
        return A;
    }
    int get_B() {
        return B;
    }
    int get_C() {
        return C;
    }
    int get_D() {
        return D;
    }
    std::string get_name() {
        return name;
    }
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        name = "Четырёхугольник:";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм: ";
    }
};

class Rectangl : public Parallelogram {
public:
    Rectangl(int a, int b) : Parallelogram(a, b, 90, 90) {
        name = "Прямоугольник: ";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {
        name = "Ромб: ";
    }
};

class Square : public Rhombus {
public:
    Square(int a) : Rhombus(a, a, a) {
        name = "Квадрат: ";
    }
};

void print_figures(std::vector <Triangle> arr1, std::vector <Quadrilateral> arr2) {
    for (int i = 0; i < arr1.size(); ++i) {
        std::cout << arr1[i].get_name() << '\n';
        std::cout << "Стороны: a=" << arr1[i].get_a() << " b=" << arr1[i].get_b() << " c=" << arr1[i].get_c() << '\n';
        std::cout << "Углы: A=" << arr1[i].get_A() << " B=" << arr1[i].get_B() << " C=" << arr1[i].get_C() << '\n';
        std::cout << '\n';
    }
    for (int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i].get_name() << '\n';
        std::cout << "Стороны: a=" << arr2[i].get_a() << " b=" << arr2[i].get_b() << " c=" << arr2[i].get_c() << " d=" << arr2[i].ger_d() << '\n';
        std::cout << "Углы: A=" << arr2[i].get_A() << " B=" << arr2[i].get_B() << " C=" << arr2[i].get_C() << " D=" << arr2[i].get_D() << '\n';
        std::cout << '\n';
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector <Triangle> all_triangle;
    std::vector <Quadrilateral> all_quadrilateral;


    all_triangle.push_back(Triangle(10, 20, 30, 50, 60, 70));
    all_triangle.push_back(Right_triangle(10, 20, 30, 50, 60));
    all_triangle.push_back(Isosceles_triangle(10, 20, 50, 60));
    all_triangle.push_back(Equilateral_triangle(30, 60));

    all_quadrilateral.push_back(Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80));
    all_quadrilateral.push_back(Parallelogram(20, 30, 30, 40));
    all_quadrilateral.push_back(Rectangl(10, 20));
    all_quadrilateral.push_back(Rhombus(30, 30, 40));
    all_quadrilateral.push_back(Square(20));

    print_figures(all_triangle, all_quadrilateral);

    return 0;
}