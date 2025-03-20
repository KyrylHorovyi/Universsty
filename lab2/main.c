#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int n, i;
    double a, xn, xk, dx;

    printf("Введіть значення a: ");
    scanf("%lf", &a);
    printf("Введіть початкове значення xn: ");
    scanf("%lf", &xn);
    printf("Введіть кінцеве значення xk: ");
    scanf("%lf", &xk);
    printf("Введіть крок x: ");
    scanf("%lf", &dx);

    n = (xk - xn) / dx + 1;

    double last_x = xn + (n - 1) * dx;
    if (last_x > xk) {
        n--;
    }

    double Z[n];

    for (i = 0; i < n; i += 1) {
        double x = xn + i * dx;
        Z[i] = a * exp(x);
    }

    printf("Результати:\n");
    for (i = 0; i < n; i += 1) {
        printf("Z[%d] = %4.2lf\n", i, Z[i]);
    }

    return 0;
}