#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void solverFunc(double a, double b, double c, double *root1, double *root2) {
    double discriminant = b*b - 4*a*c;
    *root1 = (-b + sqrt(discriminant)) / (2*a);
    *root2 = (-b - sqrt(discriminant)) / (2*a);
}

double calculResFunc(double a_param) {
    double x1, x2, y1, y2;
    
    solverFunc(2, 1, -4, &x1, &x2);
    
    solverFunc(a_param, 2, -1, &y1, &y2);
    
    return (x1 + y1) / (x2 + y2);
}

int main() {

    system("chcp 65001");

    double a;
    printf("Введіть значення параметра a: ");
    scanf("%lf", &a);
    
    double z = calculResFunc(a);
    printf("Результат обчислення z = %.4f\n", z);
    
    return 0;
}