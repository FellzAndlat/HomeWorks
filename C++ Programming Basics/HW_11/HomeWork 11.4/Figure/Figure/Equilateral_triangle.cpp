#include "Equilateral_triangle.h"

namespace Figure {
    Equilateral_triangle::Equilateral_triangle(int a, int b, int c, int A, int B, int C) : Isosceles_triangle(a, b, c, A, B, C) {
        if (a != b || b != c || a != b || A != B || B != C || C != A) {
            throw error::Creation_error("������ �������� ������. �������: ��� ������� �� �����");
        }
        else {
            name = "�������������� �����������: ";
        }

    }
}