#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CAMPS 77
#define MAX_LENGTH 122

struct Camping {
    char name[MAX_LENGTH];
    char location[MAX_LENGTH];
    float dailyprice;
};

int main() {

    system("chcp 65001");

    struct Camping camps[MAX_CAMPS];
    int numCamps = 0;
    char searchLoc[MAX_LENGTH];
    
    printf("Введіть кількість кемпінгів (<%d): ", MAX_CAMPS);
    scanf("%d", &numCamps);
    getchar();
    
    for (int i = 0; i < numCamps; i += 1) {
        printf("\nКемпінг №%d:\n", i + 1);
        
        printf("Назва: ");
        fgets(camps[i].name, MAX_LENGTH, stdin);
        camps[i].name[strcspn(camps[i].name, "\n")] = '\0';
        
        printf("Місце розміщення: ");
        fgets(camps[i].location, MAX_LENGTH, stdin);
        camps[i].location[strcspn(camps[i].location, "\n")] = '\0';
        
        printf("Вартість однієї доби перебування: ");
        scanf("%f", &camps[i].dailyprice);
        getchar();
    }
    
    printf("\nВведіть місцевість для пошуку кемпінгів: ");
    fgets(searchLoc, MAX_LENGTH, stdin);
    searchLoc[strcspn(searchLoc, "\n")] = '\0';
    
    FILE* outputfile = fopen("campingRes.txt", "w");
    if (outputfile == NULL) {
        printf("Err\n");
        return 1;
    }
    
    printf("\nРезультати пошуку в місцевості '%s':\n", searchLoc);
    fprintf(outputfile, "Результати пошуку в місцевості '%s':\n", searchLoc);
    
    int found = 0;
    for (int i = 0; i < numCamps; i += 1) {
        if (strcmp(camps[i].location, searchLoc) == 0) {
            printf("\nНазва: %s\n", camps[i].name);
            printf("Місце розміщення: %s\n", camps[i].location);
            printf("Вартість доби: %.2f грн\n", camps[i].dailyprice);
            
            fprintf(outputfile, "\nНазва: %s\n", camps[i].name);
            fprintf(outputfile, "Місце розміщення: %s\n", camps[i].location);
            fprintf(outputfile, "Вартість доби: %.2f грн\n", camps[i].dailyprice);
            
            found = 1;
        }
    }
    
    if (!found) {
        printf("Кемпінгів у місцевості '%s' не знайдено.\n", searchLoc);
        fprintf(outputfile, "Кемпінгів у місцевості '%s' не знайдено.\n", searchLoc);
    }
    
    fclose(outputfile);
    printf("\nRes also in file'campingRes.txt'\n");
    
    return 0;
}