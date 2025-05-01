#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N_MAX 20
#define DEFAULT_VALUE 1e38

double calculateZ(double P_i, double Q_i) {
    double discriminant = P_i * P_i - 4 * Q_i;
    
    if (discriminant >= 0) {
        double sqrt_discriminant = sqrt(discriminant);
        double root1 = (-P_i + sqrt_discriminant) / 2;
        double root2 = (-P_i - sqrt_discriminant) / 2;
        return fmax(root1, root2);
    } else {
        return DEFAULT_VALUE;
    }
}

int main() {

    system("chcp 65001");

    int N;
    double P[N_MAX], Q[N_MAX], Z[N_MAX];
    
    printf("Введіть розмір масивів (< 20): ");
    scanf("%d", &N);
    
    if (N >= 20 || N <= 0) {
        printf("Дотримуйся вимог!\n");
        return 1;
    }
    
    printf("Введіть елементи масиву P:\n");
    for (int i = 0; i < N; i += 1) {
        printf("P [%d]: ", i + 1);
        scanf("%lf", &P[i]);
    }
    
    printf("Введіть елементи масиву Q:\n");
    for (int i = 0; i < N; i += 1) {
        printf("Q [%d]: ", i + 1);
        scanf("%lf", &Q[i]);
    }
    
    for (int i = 0; i < N; i += 1) {
        Z[i] = calculateZ(P[i], Q[i]);
    }
    
    printf("Масив Z:\n");
    for (int i = 0; i < N; i += 1) {
        if (Z[i] == DEFAULT_VALUE) {
            printf("Z[%d] = 1e38\n", i + 1);
        } else {
            printf("Z[%d] = %lf\n", i + 1, Z[i]);
        }
    }
    
    return 0;
}