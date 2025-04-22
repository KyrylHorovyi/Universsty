#include <stdio.h>
#include <stdlib.h>

int main() {
    
    system("chcp 65001");

    int M, N;
    
    printf("Введіть кількість рядків (M): ");
    scanf("%d", &M);
    printf("Введіть кількість стовпців (N): ");
    scanf("%d", &N);

    int C[M][N];
    int B[N];

    printf("Введіть елементи матриці C[%d][%d]:\n", M, N);
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("Введіть елемент C[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &C[i][j]);
        }
    }

    for (int j = 0; j < N; j += 1) {
        B[j] = 0;
        for (int i = 0; i < M; i += 1) {
            B[j] += C[i][j];
        }
    }

    printf("Масив B:\n");
    for (int j = 0; j < N; j += 1) {
        printf("%d ", B[j]);
    }
    printf("\n");

    return 0;
}