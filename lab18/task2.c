#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void inputArray(double *array, int size);
void processArray(double *array, int size, double *s, double *p, double *sum_sin, double *sum_cos, double *sum_tan);
double calculateY(double *x, int n, double *y, int m);

int main() {

    system("chcp 65001");

    int n = 3;
    int m = 2;

    double x[n];
    double y[m];

    printf("Введіть %d елементів масиву x:\n", n);
    inputArray(x, n);

    printf("Введіть %d елементів масиву y:\n", m);
    inputArray(y, m);

    double result = calculateY(x, n, y, m);
    printf("Результат обчислення y: %lf\n", result);

    return 0;
}

void inputArray(double *array, int size) {
    for (int i = 0; i < size; i += 1) {
        printf("Елемент %d: ", i + 1);
        scanf("%lf", &array[i]);
    }
}

void processArray(double *array, int size, double *s, double *p, double *sum_sin, double *sum_cos, double *sum_tan) {
    *s = 0;
    *p = 1;
    *sum_sin = 0;
    *sum_cos = 0;
    *sum_tan = 0;

    for (int i = 0; i < size; i += 1) {
        *s += array[i];
        *p *= array[i];
        *sum_sin += array[i] * sin(array[i]);
        *sum_cos += array[i] * cos(array[i]);
        *sum_tan += array[i] * tan(array[i]);
    }
}

double calculateY(double *x, int n, double *y, int m) {
    double s_x, p_x, sum_sin_x, sum_cos_x, sum_tan_x;
    processArray(x, n, &s_x, &p_x, &sum_sin_x, &sum_cos_x, &sum_tan_x);

    double A = s_x * sum_sin_x;
    double B = p_x * sum_cos_x;
    double C = (s_x + p_x) * sum_tan_x;

    double s_y, p_y, sum_tan_y, sum_exp_y, sum_cos_y;
    s_y = 0;
    p_y = 1;
    sum_tan_y = 0;
    sum_exp_y = 0;
    sum_cos_y = 0;

    for (int i = 0; i < m; i += 1) {
        s_y += y[i];
        p_y *= y[i];
        sum_tan_y += y[i] * tan(y[i]);
        sum_exp_y += y[i] * exp(y[i]);
        sum_cos_y += y[i] * cos(y[i]);
    }

    double D = s_y * sum_tan_y;
    double E = p_y * sum_exp_y;
    double F = (s_y + p_y) * sum_cos_y;

    double numerator = A + B * cos(C);
    double denominator = D + E * sin(F);

    return numerator / denominator;
}