#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countElements(int rows, int cols, double matrix[rows][cols]) {
    int count = 0;
    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (matrix[i][j] > 0 && matrix[i][j] < 1) {
                count += 1;
            }
        }
    }
    return count;
}

int main() {

    system("chcp 65001");

    srand(time(0)); // буду використовувати генератор чисел, бо довго вводити з клавіатури

    double x[10][15];
    printf("Матриця x(10,15):\n");
    for (int i = 0; i < 10; i += 1) {
        for (int j = 0; j < 15; j += 1) {
            x[i][j] = (double)rand() / RAND_MAX * 2.0; // зменшив розкид рандомайзеру для виконання завдання
            printf("%.2f ", x[i][j]);
        }
        printf("\n");
    }

    double y[20][12];
    printf("\nМатриця y(20,12):\n");
    for (int i = 0; i < 20; i += 1) {
        for (int j = 0; j < 12; j += 1) {
            y[i][j] = (double)rand() / RAND_MAX * 2.0;
            printf("%.2f ", y[i][j]);
        }
        printf("\n");
    }

    int countX = countElements(10, 15, x);
    printf("\nКількість елементів у матриці x, що задовольняють умову 0 < x(i,j) < 1: %d\n", countX);

    int countY = countElements(20, 12, y);
    printf("Кількість елементів у матриці y, що задовольняють умову 0 < y(i,j) < 1: %d\n", countY);

    return 0;
}