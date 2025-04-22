#include <stdio.h>
#include <stdlib.h>
#define N 3

//хотів оголосити функції після головної частини, але було багато попереджень компілятора
void minIncol(double matrix[N][N], double minElements[N]) {
    for (int col = 0; col < N; col += 1) {
        double min = matrix[0][col];
        for (int row = 1; row < N; row += 1) {
            if (matrix[row][col] < min) {
                min = matrix[row][col];
            }
        }
        minElements[col] = min;
    }
}

void showMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    system("chcp 65001");

    double matrix[N][N] = {
        {5.2, 3.1, 4.9},
        {2.8, 1.7, 6.3},
        {7.4, 0.5, 9.2}
    };
    double minElements[N];

    printf("Матриця A:\n");
    showMatrix(matrix);

    minIncol(matrix, minElements);

    printf("\n Найменші елементи в стовпцях:\n");
    for (int i = 0; i < N; i += 1) {
        printf("Стовпець %d: %.2f\n", i + 1, minElements[i]);
    }

    return 0;
}
