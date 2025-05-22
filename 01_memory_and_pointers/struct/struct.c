#include <stdio.h>
#include <stdlib.h>

struct Punto
{
    double x;
    double y;
};

int main()
{
//         [point]
// +----------+----------+
// |    0.0   |    1.0   |
// |     x    |     y    |
// +----------+----------+

    struct Punto point = {.x = 0, .y = 1};
    printf("x: %f, y: %f\n", point.x, point.y);

    // [punto] (en stack)
    // +---------+
    // |   --->  | ──→ [heap]
    // +---------+       ↓
    //             +--------+--------+
    //             |  6.4   |  7.9   |
    //             |   x    |   y    |
    //             +--------+--------+

    struct Punto *punto = malloc(sizeof(struct Punto));
    punto->x = 6.4;
    punto->y = 7.9;
    printf("x: %f, y: %f\n", punto->x, punto->y);
    free(punto);
}
