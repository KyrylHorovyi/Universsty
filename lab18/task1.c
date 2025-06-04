#include <stdio.h>
#include <stdlib.h>

float metersToFeet(float value);
float celsiusToFahrenheit(float value);
float kilogramsToPounds(float value);
float litersToGallons(float value);
float kilometersToMiles(float value);

int main() {

    system("chcp 65001");

    float (*converters[5])(float) = {metersToFeet, celsiusToFahrenheit, kilogramsToPounds, litersToGallons, kilometersToMiles};
    
    const char* converter_names[5] = {"Метри в фути", "Градуси Цельсія в Фаренгейти", "Кілограми в фунти", "Літри в галони", "Кілометри в милі"};
    
    float value;
    printf("Введіть значення для конвертації: ");
    scanf("%f", &value);
    
    printf("\nРезультати конвертації для %.2f:\n", value);
    
    for (int i = 0; i < 5; i += 1) {
        float result = converters[i](value);
        printf("%s: %.2f\n", converter_names[i], result);
    }
    
    return 0;
}

float metersToFeet(float value) {
    return value * 3.28084f;
}

float celsiusToFahrenheit(float value) {
    return (value * 9.0f/5.0f) + 32.0f;
}

float kilogramsToPounds(float value) {
    return value * 2.20462f;
}

float litersToGallons(float value) {
    return value * 0.264172f;
}

float kilometersToMiles(float value) {
    return value * 0.621371f;
}