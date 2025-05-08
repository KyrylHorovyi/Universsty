#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swapper(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int main() {

    system("chcp 65001");

    char *first = malloc(50 * sizeof(char));
    char *second = malloc(50 * sizeof(char));
    
    strcpy(first, "Перший рядок");
    strcpy(second, "Другий рядок");
    
    printf("До свапу:\n");
    printf("first: %s\n", first);
    printf("second: %s\n", second);
    
    swapper(&first, &second);
    
    printf("\nПісля свапу:\n");
    printf("first: %s\n", first);
    printf("second: %s\n", second);
    
    free(first);
    free(second);
    
    return 0;
}