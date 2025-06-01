#include <stdio.h>

int main() {

    int arr[10];
    int *p, *pmax; // створюємо два покажчики на інт
    int i, n;

    printf (" n="); scanf("%d",&n); // введення кількості елементів масиву

    printf (" input value arr \n");

    for (i=0;i<n; i++) // введення значень масиву
    scanf("%d",&arr[i]);

    pmax = arr; // беремо що максимум це перший елемент масиву

    for ( p = arr+1; p < arr+n; p++)
    if ( *p > *pmax )
    pmax = p ; // проходимось по масиву з другого елемента, якщо елемент більше за pmax, то оновлюємо pmax

    printf ("Max element =% d \n",*pmax); // виводимо значення pmax
    printf("its number =%d \n", pmax-arr+1); // виводимо номер елемента (індекс+1)

}