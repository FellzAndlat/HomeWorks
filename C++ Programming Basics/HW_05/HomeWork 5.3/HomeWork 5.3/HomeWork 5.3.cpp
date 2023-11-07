#include <iostream>
#include <cstring>
#include <Windows.h>
#include <vector>

class Figure {
protected:
    std::string name;
    int size;
public:
    virtual void print_info() {
        std::cout << name << '\n';
        if (check() == 1) {
            std::cout << "Правильная" << '\n';
        }
        else {
            std::cout << "Неправильная" << '\n';
        }
        std::cout << "Колчество сторон: " << size << '\n';
        std::cout << '\n';
    }
    virtual bool check() {
        bool x = 0;
        if (size == 0) {
            x = 1;
            return x;
        }
        return x;
    }
    Figure() {
        name = "Фигура: ";
        size = 0;
    }
    
};

class Triangle: public Figure {
protected:
    int a, b, c;
    int A, B, C;
    std::string name;
public:
    void print_info() {
        std::cout << name << '\n';
        if (check() == 1) {
            std::cout << "Правильная" << '\n';
        }
        else {
            std::cout << "Неправильная" << '\n';
        }
        std::cout << "Колчество сторон: " << size << '\n';
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
        std::cout << '\n';
    }
    bool check() {
        bool x = 0;
        if (size == 3 && A + B + C == 180) {
            x = 1;
            return x;
        }
        return x;
    }

    Triangle(int a, int b, int c, int A, int B, int C): Figure () {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        name = "Треугольник: ";
        size = 3;
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

class Quadrilateral:public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;
public:
    void print_info() {
        std::cout << name << '\n';
        if (check() == 1) {
            std::cout << "Правильная" << '\n';
        }
        else {
            std::cout << "Неправильная" << '\n';
        }
        std::cout << "Колчество сторон: " << size << '\n';
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << '\n';
        std::cout << '\n';
    }
    bool check() {
        bool x = 0;
        if (size == 4 && A + B + C + D == 360) {
            x = 1;
            return x;
        }
        return x;
    }

    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D): Figure() {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        size = 4;
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
    Square(int a) : Rhombus(a, 90, 90) {
        name = "Квадрат: ";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Figure*> all_figure;

    all_figure.push_back(new Figure());
    all_figure.push_back(new Triangle(10, 20, 30, 50, 60, 70));
    all_figure.push_back(new Right_triangle(10, 20, 30, 50, 60));
    all_figure.push_back(new Right_triangle(10, 20, 30, 50, 40));
    all_figure.push_back(new Isosceles_triangle(10, 20, 50, 60));
    all_figure.push_back(new Equilateral_triangle(30, 60));
    all_figure.push_back(new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80));
    all_figure.push_back(new Rectangl(10, 20));
    all_figure.push_back(new Square(20));
    all_figure.push_back(new Parallelogram(20, 30, 30, 40));
    all_figure.push_back(new Rhombus(30, 30, 40));

    for (int i = 0; i < all_figure.size(); ++i) {
        all_figure[i]->print_info();
    }


    return 0;
}