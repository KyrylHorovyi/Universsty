#include <stdio.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int X[15] = {5, 12, 8, 19, 3, 7, 15, 2, 11, 6, 14, 9, 4, 17, 10};
    int A = 9;
    int n = 15;
    
    printf("Початковий масив X:\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", X[i]);
    }
    printf("\n\n");
    
    int linearRes = linearSearch(X, n, A);
    if (linearRes == -1) {
        printf("Елемент %d не знайдено за допомогою лінійного пошуку.\n", A);
    } else {
        printf("Елемент %d знайдено за допомогою лінійного пошуку на позиції %d.\n", A, linearRes);
    }
    
    sortarr(X, n);
    
    printf("\nВідсортований масив X (за спаданням):\n");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", X[i]);
    }
    printf("\n\n");
    
    int binaryRes = binarySearch(X, 0, n-1, A);
    if (binaryRes == -1) {
        printf("Елемент %d не знайдено за допомогою бінарного пошуку.\n", A);
    } else {
        printf("Елемент %d знайдено за допомогою бінарного пошуку на позиції %d.\n", A, binaryRes);
    }
    
    return 0;
}


//Пропишу функції тут, а взагалі хотів винести в окремий файл


int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i += 1) {
        if (arr[i] == x) {
            return i + 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x) {
            return mid +1;
        }
        
        if (arr[mid] < x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1;
}

void sortarr(int arr[], int n) {
    for (int i = 0; i < n-1; i += 1) {
        for (int j = 0; j < n-i-1; j += 1) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
