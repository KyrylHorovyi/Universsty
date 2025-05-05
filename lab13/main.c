#include <stdio.h>
#include <stdlib.h>

double ResSum(int n) {
    if (n == 1) {
        return 1.0;
    }
    else {
        return 1.0 / n + ResSum(n - 1);
    }
}

int main() {

    system("chcp 65001");
    
    int n;
    printf("Введіть n: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("n має бути більше або рівне 1\n");
        return 1;
    }
    
    double result = ResSum(n);
    printf("s = %lf\n", result);
    
    return 0;
}