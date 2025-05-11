#include <stdio.h>
#include "formula1.h"
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int N;
    printf("Введіть кількість точок: ");
    scanf("%d", &N);

    double points[N][2];

    for (int i = 0; i < N; i += 1) {
        printf("Точка %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }

    printf("\nВідстані між точками:\n");
    for (int i = 0; i < N - 1; i += 1) {
        double x1 = points[i][0], y1 = points[i][1];
        double x2 = points[i+1][0], y2 = points[i+1][1];

        double dist = DISTANCE(x1, y1, x2, y2);
        printf("Відстань між точкою %d і %d: %.2lf\n", i + 1, i + 2, dist);
    }

    return 0;
}