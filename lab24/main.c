#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "camping.dat"

typedef struct {
    char name[50];
    char location[50];
    float price_per_day;
} Camping;

void capmsToFile(Camping *campings, int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Err");
        exit(1);
    }

    fwrite(campings, sizeof(Camping), count, file);
    fclose(file);
}

void newPrices(int count, const char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        perror("Err");
        exit(1);
    }

    Camping temp;

    for (int i = 0; i < count; i++) {
        fseek(file, i * sizeof(Camping), SEEK_SET);
        fread(&temp, sizeof(Camping), 1, file);

        printf("Поточна ціна для \"%s\": %.2f\n", temp.name, temp.price_per_day);
        printf("Введіть нову ціну: ");
        scanf("%f", &temp.price_per_day);

        fseek(file, -sizeof(Camping), SEEK_CUR);
        fwrite(&temp, sizeof(Camping), 1, file);
    }

    fclose(file);
}

void campsFromFile(int count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Err");
        exit(1);
    }

    Camping temp;
    printf("\nОновлений список кемпінгів:\n");
    for (int i = 0; i < count; i++) {
        fread(&temp, sizeof(Camping), 1, file);
        printf("Назва: %s, Розміщення: %s, Ціна за добу: %.2f\n", temp.name, temp.location, temp.price_per_day);
    }

    fclose(file);
}

int main() {

    system("chcp 65001");

    int count;
    printf("Введіть кількість кемпінгів: ");
    scanf("%d", &count);

    Camping *campings = (Camping *)malloc(count * sizeof(Camping));
    if (!campings) {
        perror("Err");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Кемпінг %d:\n", i + 1);
        printf("Назва: ");
        scanf(" %[^\n]", campings[i].name);
        printf("Місце розміщення: ");
        scanf(" %[^\n]", campings[i].location);
        printf("Ціна за добу: ");
        scanf("%f", &campings[i].price_per_day);
    }

    capmsToFile(campings, count, FILE_NAME);
    newPrices(count, FILE_NAME);
    campsFromFile(count, FILE_NAME);

    free(campings);
    return 0;
}
