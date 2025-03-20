#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    system("chcp 65001");

    int N;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &N);

    float array[N];
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < N; i += 1) {
        scanf("%f", &array[i]);
    }

    float min_elem = array[0];
    for (int i = 1; i < N; i += 1) {
        if (array[i] < min_elem) {
            min_elem = array[i];
        }
    }
    printf("Мінімальний елемент масиву: %.2f\n", min_elem);

    int first_pos = -1, last_pos = -1;

    for (int i = 0; i < N; i += 1) {
        if (array[i] > 0) {
            first_pos = i;
            break;
        }
    }

    for (int i = N - 1; i >= 0; i -= 1) {
        if (array[i] > 0) {
            last_pos = i;
            break;
        }
    }

    float sum = 0;
    if (first_pos < last_pos) {
        for (int i = first_pos + 1; i < last_pos; i += 1) {
            sum += array[i];
        }
        printf("Сума елементів між першим і останнім додатним елементом: %.2f\n", sum);
    } else {
        printf("Суму елементів масиву, розміщених між першим і останнім додатними елементами знайти неможливо.\n");
    }
    return 0;
}