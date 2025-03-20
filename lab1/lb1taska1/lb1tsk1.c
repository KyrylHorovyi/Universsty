#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    
    system("chcp 65001");  
    
    int N;
    printf("Введіть кількість чисел: ");
    scanf("%d", &N);

    int MAS[N];
    for (int i = 0; i < N; i += 1)
    {
        printf("Введіть число %d: ", i + 1);
        scanf("%d", &MAS[i]);
    }

    int sum_par = 0;
    int count_par = 0;
    long long dob_nepar = 1; //щоб не залісти в оверфлоу
    int count_nepar = 0;
    int max_value = MAS[0];
    int max_index = 0;
    
    for (int i = 0; i < N; i += 1)
    {
        if (MAS[i] % 2) {
            dob_nepar *= MAS[i];
            count_nepar++;
        } else {
            sum_par += MAS[i];
            count_par++;
        }
    
        if (MAS[i] > max_value) {
            max_value = MAS[i];
            max_index = i;
        }
    }
    //res
    if (count_par > 0) {
        float average_par = (float)sum_par / count_par;
        printf("Сума парних чисел: %d\n", sum_par);
        printf("Середнє арифметичне парних чисел: %.2f\n", average_par);
    } else {
        puts("Парних чисел немає.\n");
    }

    if (count_nepar > 0) {
        printf("Добуток непарних чисел: %lld\n", dob_nepar);
        double avg_geom = pow(dob_nepar, 1.0 / count_nepar);
        printf("Середнє геометричне непарних чисел: %.2f\n", avg_geom);
    } else {
        puts("Непарних чисел немає.\n");
    }

    printf("Максимальне значення: %d. Його номер в масиві = %d", max_value, max_index + 1);

    return 0;
}