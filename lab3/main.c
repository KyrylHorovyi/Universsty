#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int N;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &N);
    
    double arr_A[N];
    for(int i = 0; i < N; i += 1) {
        printf("A[%d] = ", i);
        scanf("%lf", &arr_A[i]);
    }

    double arr_B[N];
    for(int i = 0; i < N; i += 1) {
        printf("B[%d] = ", i);
        scanf("%lf", &arr_B[i]);
    }

    double sum = 0.0;
    const double epsilon = 1e-9;

    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            if (fabs(arr_A[i] - arr_B[j]) < epsilon) { // при порівнянні з типом дабл були проблеми, намагався вирішити
                sum += arr_A[i];
                break;
            }
        }
    }
    printf("Сума спільних елементів = %.2lf\n", sum);
    return 0;
}