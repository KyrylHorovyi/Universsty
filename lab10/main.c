#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputArray(float arr[], int size) {
    printf("Введіть %d елементів масиву:\n", size);
    for (int i = 0; i < size; i += 1) {
        printf("Елемент %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
}

void analyzeArray(float arr[], int size, float limit, float *sum, float *geomAvg) {
    *sum = 0;
    *geomAvg = 1;
    int count = 0;
    
    for (int i = 0; i < size; i += 1) {
        if (arr[i] > 0 && arr[i] < limit) {
            *sum += arr[i];
            *geomAvg *= arr[i];
            count++;
        }
    }
    
    if (count > 0) {
        *geomAvg = pow(*geomAvg, 1.0 / count);
    } else {
        *geomAvg = 0;
    }
}

int main() {

    system("chcp 65001");

    int size1, size2, size3;
    float limit;
    
    printf("Введіть розмір першого масиву: ");
    scanf("%d", &size1);
    printf("Введіть розмір другого масиву: ");
    scanf("%d", &size2);
    printf("Введіть розмір третього масиву: ");
    scanf("%d", &size3);
    printf("Введіть граничне число: ");
    scanf("%f", &limit);
    
    float arr1[size1], arr2[size2], arr3[size3];
    float sum1, sum2, sum3, geomAvg1, geomAvg2, geomAvg3;
    
    inputArray(arr1, size1);
    analyzeArray(arr1, size1, limit, &sum1, &geomAvg1);
    
    inputArray(arr2, size2);
    analyzeArray(arr2, size2, limit, &sum2, &geomAvg2);
    
    inputArray(arr3, size3);
    analyzeArray(arr3, size3, limit, &sum3, &geomAvg3);
    
    printf("\nРезультати для першого масиву:\n");
    printf("Сума додатніх елементів менших за %.2f: %.2f\n", limit, sum1);
    printf("Середнє геометричне: %.2f\n", geomAvg1);
    
    printf("\nРезультати для другого масиву:\n");
    printf("Сума додатніх елементів менших за %.2f: %.2f\n", limit, sum2);
    printf("Середнє геометричне: %.2f\n", geomAvg2);
    
    printf("\nРезультати для третього масиву:\n");
    printf("Сума додатніх елементів менших за %.2f: %.2f\n", limit, sum3);
    printf("Середнє геометричне: %.2f\n", geomAvg3);
    
    return 0;
}