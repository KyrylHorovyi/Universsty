#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    system("chcp 65001");

    int N, M; // в умові до завдання чомусь другий масив теж з N ел, додав M для коректності
    
    srand(time(NULL));
    
    N = rand() % 998 + 3; // у нас нема кінцевої межі, але я вкажу 1000
    M = rand() % 19 + 1; // зсунув правіше нуля, щоб взагалі масив існував
    
    printf("Згенеровано N = %d, M = %d\n", N, M);
    
    int *A = (int*)malloc(N * sizeof(int));
    int *B = (int*)malloc(M * sizeof(int));
    
    if (A == NULL || B == NULL) {
        printf("Err\n");
        return 1;
    }
    
    printf("Масив A(%d): ", N);
    for (int i = 0; i < N; i += 1) {
        A[i] = rand() - RAND_MAX / 2;
        printf("%d ", A[i]);
    }
    printf("\n");
    
    printf("Масив B(%d): ", M);
    for (int i = 0; i < M; i += 1) {
        B[i] = rand() - RAND_MAX / 2;
        printf("%d ", B[i]);
    }
    printf("\n");
    
    int max_A = A[0];
    int index_A = 0;
    for (int i = 1; i < N; i += 1) {
        if (A[i] > max_A) {
            max_A = A[i];
            index_A = i;
        }
    }
    
    int max_B = B[0];
    int index_B = 0;
    for (int i = 1; i < M; i += 1) {
        if (B[i] > max_B) {
            max_B = B[i];
            index_B = i;
        }
    }
    
    printf("Для масиву A: найбільше значення = %d, індекс = %d\n", max_A, index_A);
    printf("Для масиву B: найбільше значення = %d, індекс = %d\n", max_B, index_B);
    
    free(A);
    free(B);
    
    return 0;
}