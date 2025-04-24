#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define M 3
#define N 2
#define P 3

int main() {

    system("chcp 65001");

    int A[M][N], B[N][P], C[M][P];
    int i, j, k;

    printf("Введіть матрицю A (%d x %d):\n", M, N);
    for (i = 0; i < M; i += 1) {
        for (j = 0; j < N; j += 1) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Введіть матрицю B (%d x %d):\n", N, P);
    for (i = 0; i < N; i += 1) {
        for (j = 0; j < P; j += 1) {
            printf("B[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < M; i += 1) {
        for (j = 0; j < P; j += 1) {
            C[i][j] = 0;
            for (k = 0; k < N; k += 1) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Результат множення (матриця C %d x %d):\n", M, P);
    for (i = 0; i < M; i += 1) {
        for (j = 0; j < P; j += 1) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    int max_negative = INT_MIN;
    int row = -1, col = -1;

    for (i = 0; i < M; i += 1) {
        for (j = 0; j < P; j += 1) {
            if (C[i][j] < 0 && C[i][j] > max_negative) {
                max_negative = C[i][j];
                row = i;
                col = j;
            }
        }
    }

    if (max_negative == INT_MIN) {
        printf("Від'ємних елементів у матриці C немає.\n");
    } else {
        printf("Найбільший від'ємний елемент: %d\n", max_negative);
        printf("Розташований у рядку %d, стовпчику %d\n", row + 1, col + 1);
    }

    return 0;
}