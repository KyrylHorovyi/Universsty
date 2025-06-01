#include <stdio.h>
#include <conio.h>

int main() {

    float x, y; // оголошуємо 2 змінні типу флоат
    float *x_ptr,*y_ptr; // створюємо покажчики x_ptr і y_ptr на флоат
    
    x_ptr = &x; // присвоюємо адресу змінної х

    *x_ptr = 5; // розіменовуємо x_ptr і записуємо туди значення 5, звідси х = 5

    x = 5.5 + *x_ptr; // х = 5.5 + 5 = 10.5

    y_ptr = x_ptr; // тепер оба вказують на одну й ту саму адресу ікса

    y = *y_ptr / 2+ *x_ptr; // у = 10.5/2 + 10.5 = 15.75

    y_ptr=&y; // присвоїли адресу ігрика нашому покажчику

    printf("The value of x= %f y=%f\n", x, y); // вивід значень 10.5 і 15.75
    printf("The address of x = %p y = %p\n", &x, &y); // вивід адрес
    printf("The value of x_ptr = %p y_ptr = %p\n", x_ptr, y_ptr); // вивід адрес
    printf("The value that x_ptr points to is %f .\n", *x_ptr); // 10.5
    printf("The value that y_ptr points to is %f.\n", *y_ptr); // 15.75
    printf("The address of x_ptr is %p.\n", &x_ptr); // вивід адреси самого покажчика
    printf("The address of y_ptr is %p.\n", &y_ptr); // вивід адреси самого покажчика
    puts("====================================================");

    getch();

}
