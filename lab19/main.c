#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 5
#define M 4

void inpArr(double arr[], int size) {
    printf("Введіть %d елементів масиву:\n", size);
    for (int i = 0; i < size; i += 1) {
        printf("Елемент %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
}

void calcArr(double arr[], int size, double *result1, double *result2, double *result3, double *sum, double *product, int zARRR) {
    *sum = 0.0;
    *product = 1.0;
    
    for (int i = 0; i < size; i += 1) {
        *sum += arr[i];
        *product *= arr[i];
    }
    
    double temp1 = 0.0, temp2 = 0.0, temp3 = 0.0;
    
    for (int i = 0; i < size; i++) {
        if (zARRR) {
            temp1 += arr[i] * exp(arr[i]);
            temp2 += arr[i] * cos(arr[i]);
            temp3 += arr[i] * sin(arr[i]);
        } else {
            temp1 += arr[i] * sin(arr[i]);
            temp2 += arr[i] * tan(arr[i]);
            temp3 += arr[i] * fabs(arr[i]);
        }
    }
    
    *result1 = (*sum) * temp1;
    *result2 = (*product) * temp2;
    *result3 = (*product) * temp3;
}

int main() {

    system("chcp 65001");

    double z[N], beta[M];
    
    inpArr(z, N);
    inpArr(beta, M);
    
    double A, B, C, s_z, p_z;
    calcArr(z, N, &A, &B, &C, &s_z, &p_z, 1);
    
    double D, E, F, s_beta, p_beta;
    calcArr(beta, M, &D, &E, &F, &s_beta, &p_beta, 0);
    
    double omega = (A + B + sin(C)) / (D + E + cos(F));
    
    printf("\nРезультати:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);
    printf("E = %lf\n", E);
    printf("F = %lf\n", F);
    printf("ω = %lf\n", omega);
    
    return 0;
}