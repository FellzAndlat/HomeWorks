#include "Rhombus.h"

Rhombus::Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(a, b, c, d, A, B, C, D) {
    if (a != b || b != c || c != d || d != a || A != C || B != D) {
        throw Creation_error("������ �������� ������. �������: ��� ������� �� ����� ��� ���� �� ����� �� �����");
    }
    else {
        name = "����: ";
    }
    
}