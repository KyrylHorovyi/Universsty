#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

int main() {

    system("chcp 65001");

    double p[ROWS][COLS];
    double a, b;

    FILE* inputFile = fopen("vhid.txt", "r");
    if (inputFile == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i += 1) {
        for (int j = 0; j < COLS; j += 1) {
            if (fscanf(inputFile, "%lf", &p[i][j]) != 1) {
                printf("Error\n");
                fclose(inputFile);
                return 1;
            }
        }
    }
    fclose(inputFile);

    printf("Введіть значення a: ");
    scanf("%lf", &a);
    printf("Введіть значення b: ");
    scanf("%lf", &b);

    double replacement = (a + b) / 2;
    for (int i = 0; i < ROWS; i += 1) {
        for (int j = 0; j < COLS; j += 1) {
            if (p[i][j] >= a && p[i][j] <= b) {
                p[i][j] = replacement;
            }
        }
    }

    FILE* outputFile = fopen("exit.txt", "w");
    if (outputFile == NULL) {
        printf("Eror\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i += 1) {
        for (int j = 0; j < COLS; j += 1) {
            fprintf(outputFile, "%.2lf ", p[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);

    printf("Результат у exit.txt\n");
    return 0;
}