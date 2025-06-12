#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FLOWERS 100
#define MAX_NAME_LEN 50
#define MAX_COLOR_LEN 27

typedef struct {
    char name[MAX_NAME_LEN];
    char color[MAX_COLOR_LEN];
    float price;
} Flower;

int main() {

    system("chcp 65001");

    Flower flowers[MAX_FLOWERS];
    int count = 0;
    char search_color[MAX_COLOR_LEN];
    float max_price;
    
    printf("Введіть дані про квіти (для завершення введіть 'end' у назві):\n");
    while (count < MAX_FLOWERS) {
        printf("Квітка #%d:\n", count + 1);
        printf("Назва: ");
        scanf("%s", flowers[count].name);
        
        if (strcmp(flowers[count].name, "end") == 0) {
            break;
        }
        
        printf("Колір: ");
        scanf("%s", flowers[count].color);
        printf("Вартість: ");
        scanf("%f", &flowers[count].price);
        
        count++;
    }
    
    printf("\nВведіть колір для пошуку: ");
    scanf("%s", search_color);
    printf("Введіть максимальну вартість: ");
    scanf("%f", &max_price);
    
    FILE* output_file = fopen("results.txt", "w");
    if (output_file == NULL) {
        perror("Помилка при відкритті файлу!\n");
        return 1;
    }
    
    fprintf(output_file, "Результати пошуку (колір: %s, максимальна вартість: %.2f):\n", 
            search_color, max_price);
    fprintf(output_file, "-----\n");
    
    int found = 0;
    for (int i = 0; i < count; i += 1) {
        if (strcmp(flowers[i].color, search_color) == 0 && 
            flowers[i].price <= max_price) {
            fprintf(output_file, "Назва: %s\n", flowers[i].name);
            fprintf(output_file, "Колір: %s\n", flowers[i].color);
            fprintf(output_file, "Вартість: %.2f\n", flowers[i].price);
            fprintf(output_file, "-----\n");
            found++;
        }
    }
    
    if (found == 0) {
        fprintf(output_file, "Квітів з вказаними параметрами не знайдено.\n");
    }
    
    fclose(output_file);
    printf("Результати збережено у файлі 'results.txt'\n");
    
    return 0;
}