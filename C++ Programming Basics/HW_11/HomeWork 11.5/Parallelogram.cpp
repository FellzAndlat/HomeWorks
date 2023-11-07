#include <string>
#include "Parallelogram.h"

namespace Figure {
    Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D) {
        if (a != c || b != d || A != C || B != D) {
            throw error::Creation_error("Ошибка создания фигуры. Причина: Углы или стороны по парно не равны");
        }
        else {
            name = "Параллелограмм: ";
        }
    }
}
