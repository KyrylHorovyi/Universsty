#include <stdio.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int n, i, j;
    
    printf("Введіть розмір квадратної матриці n: ");
    scanf("%d", &n);
    
    int **A = (int **)malloc(n * sizeof(int *));
    if (A == NULL) {
        printf("Err\n");
        return 1;
    }
    
    for(i = 0; i < n; i += 1) {
        A[i] = (int *)malloc(n * sizeof(int));
        if (A[i] == NULL) {
            printf("Err\n");
            for (int k = 0; k < i; k += 1) {
                free(A[k]);
            }
            free(A);
            return 1;
        }
    }
    
    printf("\nВведіть елементи матриці:\n");
    for(i = 0; i < n; i += 1) {
        for(j = 0; j < n; j += 1) {
            printf("Елемент [%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\nПочаткова матриця:\n");
    for(i = 0; i < n; i += 1) {
        for(j = 0; j < n; j += 1) {
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }
    
    for(i = 0; i < n; i += 1) {
        int max_index = 0;
        for(j = 1; j < n; j += 1) {
            if(A[i][j] > A[i][max_index]) {
                max_index = j;
            }
        }
        
        if(max_index != i) {
            int temp = A[i][i];
            A[i][i] = A[i][max_index];
            A[i][max_index] = temp;
        }
    }
    
    printf("\nМатриця після обміну:\n");
    for(i = 0; i < n; i += 1) {
        for(j = 0; j < n; j += 1) {
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }
    
    int *secondary_diagonal = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i += 1) {
        secondary_diagonal[i] = A[i][n - 1 - i];
    }
    
    printf("\nЕлементи побічної діагоналі:\n");
    for(i = 0; i < n; i += 1) {
        printf("%d ", secondary_diagonal[i]);
    }
    printf("\n");
    
    for(i = 0; i < n; i += 1) {
        free(A[i]);
    }
    free(A);
    free(secondary_diagonal);
    
    return 0;
}