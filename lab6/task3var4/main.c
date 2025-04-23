#include <stdio.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int M, N;
    
    printf("Введіть кількість рядків (M): ");
    scanf("%d", &M);
    printf("Введіть кількість стовпців (N): ");
    scanf("%d", &N);
    
    if (M < 1 || N < 1) {
        printf("Матриця порожня\n");
        return 1;
    }

    int A[M][N], B[M][N], C[M][N];
    
    printf("Введіть елементи матриці A:\n");
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Введіть елементи матриці B:\n");
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("B[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
    
    int min = C[0][0];

    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            C[i][j] = A[i][j] + B[i][j];
            if (C[i][j] < min) {
                min = C[i][j];
            }
        }
    }
    
    printf("Мінімальний елемент матриці C (A+B) = %d\n", min);
    
    return 0;
}