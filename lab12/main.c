#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void inputArr(double arr[], int n) {
    printf("Введіть %d елементів масиву:\n", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%lf", &arr[i]);
    }
}

double ResSum(double arr[], int n, double (*func1)(double), double (*func2)(double)) {
    double sum = 0.0;
    for (int i = 0; i < n; i += 1) {
        sum += arr[i] * func1(arr[i]) + pow(arr[i], 2) * func2(arr[i]);
    }
    return sum;
}

int main() {
    system("chcp 65001");
    
    int nx, ny, nz, nq;

    printf("Введіть кількість елементів масиву x: ");
    scanf("%d", &nx);
    printf("Введіть кількість елементів масиву y: ");
    scanf("%d", &ny);
    printf("Введіть кількість елементів масиву z: ");
    scanf("%d", &nz);
    printf("Введіть кількість елементів масиву q: ");
    scanf("%d", &nq);

    double x[nx], y[ny], z[nz], q[nq];

    inputArr(x, nx);
    inputArr(y, ny);
    inputArr(z, nz);
    inputArr(q, nq);

    double A = ResSum(x, nx, sin, cos);
    double B = ResSum(y, ny, cos, sin);
    double C = ResSum(z, nz, sin, sin);
    double D = ResSum(q, nq, cos, cos);

    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);

    return 0;
}