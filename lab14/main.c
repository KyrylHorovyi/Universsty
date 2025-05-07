#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void task(char S[], int N) {
    int len = strlen(S);
    
    if (len > N) {
        memmove(S, S + (len - N), N + 1);
    } else if (len < N) {
        int Points = N - len;
        memmove(S + Points, S, len + 1);
        memset(S, '.', Points);
    }
}

int main() {

    system("chcp 65001");
    
    char S[666];
    int N;
    
    printf("Введіть рядок S: ");
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0';
    
    printf("Введіть число N: ");
    scanf("%d", &N);
    
    task(S, N);
    
    printf("Результат: %s\n", S);
    return 0;
}