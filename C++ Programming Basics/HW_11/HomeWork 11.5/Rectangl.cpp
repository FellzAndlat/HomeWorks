#include "Rectangl.h"

namespace Figure {
    Rectangl::Rectangl(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D) {
        if (a != c || b != d || A != 90 || B != 90 || C != 90 || D != 90) {
            throw error::Creation_error("������ �������� ������.�������: ���� �� ����� 90 ��� ������� �� ����� �� �����");
        }
        name = "�������������: ";
    }
}