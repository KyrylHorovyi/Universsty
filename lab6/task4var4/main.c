#include <stdio.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int s[4][5];
    int f[4] = {0};

    printf("Введіть елементи масиву s[4][5]:\n");
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 5; j += 1) {
            printf("s[%d][%d]:", i + 1, j + 1);
            scanf("%d", &s[i][j]);
        }
    }

    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 5; j += 1) {
            if (s[i][j] > 0) {
                f[i] += s[i][j];
            }
        }
    }

    printf("Вектор f[4]:\n");
    for (int i = 0; i < 4; i += 1) {
        printf("%d ", f[i]);
    }
    printf("\n");

    return 0;
}