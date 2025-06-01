#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979323846
#define NUM_VARIANTS 3
#define MAX_TIME_STEPS 21

typedef struct {
    double T;
    double dt;
    double u0;
    double k0;
    double m;
    double f0;
    double h;
    double c;
    double tg_delta;
} VariantData;

double calculate_k(double t, double T, double k0, double m) {
    if (t <= T / 2.0) {
        return k0 * (1.0 + m * t);
    } else {
        return k0 * (1.0 + m * T / 2.0);
    }
}

double calculate_u(double t, double T, double u0, double k) {
    if (t <= T / 4.0) {
        return u0 * (1.0 - exp(-k * t));
    } else if (t <= T / 2.0) {
        return u0 * (1.0 - exp(-k * T / 4.0));
    } else {
        return u0 * (1.0 - exp(-k * t)) * exp(-k * (t - T / 2.0));
    }
}

double calculate_f(double t, double T, double f0, double h) {
    if (t <= T / 4.0) {
        return f0 * (1.0 + h * t);
    } else if (t <= 3.0 * T / 4.0) {
        return f0 * (1.0 + h * T / 4.0);
    } else {
        return f0 * (1.0 + h * T / 4.0) * exp(-h * (t - 3.0 * T / 4.0));
    }
}

double calculate_pa(double u, double f, double c, double tg_delta) {
    return u * u * 2.0 * PI * f * c * tg_delta;
}

void write_results(const char* filename, double time[], double pa[], int num_steps, int variant_num) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Err with file!\n");
        return;
    }

    fprintf(file, "\nВаріант %d:\n", variant_num + 1);
    fprintf(file, "Час (с)\tPа (Вт)\n");
    for (int i = 0; i < num_steps; i += 1) {
        fprintf(file, "%.2f\t%.12f\n", time[i], pa[i]);
    }

    fclose(file);
}

int main() {

    system("chcp 65001");

    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Err with file!\n");
        return 1;
    }

    VariantData variants[NUM_VARIANTS];
    for (int i = 0; i < NUM_VARIANTS; i += 1) {
        if (fscanf(input_file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf",
                   &variants[i].T, &variants[i].dt, &variants[i].u0,
                   &variants[i].k0, &variants[i].m, &variants[i].f0,
                   &variants[i].h, &variants[i].c, &variants[i].tg_delta) != 9) {
            printf("Помилка зчитування даних для варіанту %d!\n", i + 1);
            fclose(input_file);
            return 1;
        }
    }
    fclose(input_file);

    FILE* output_file = fopen("results.txt", "w");
    if (output_file == NULL) {
        printf("Err with file!\n");
        return 1;
    }
    fclose(output_file);

    for (int v = 0; v < NUM_VARIANTS; v += 1) {
        VariantData var = variants[v];
        int num_steps = MAX_TIME_STEPS;
        double time[MAX_TIME_STEPS];
        double pa[MAX_TIME_STEPS];

        printf("Обчислення для варіанту %d:\n", v + 1);

        for (int i = 0; i < num_steps; i += 1) {
            double t = i * var.dt;
            time[i] = t;

            double k = calculate_k(t, var.T, var.k0, var.m);
            double u = calculate_u(t, var.T, var.u0, k);
            double f = calculate_f(t, var.T, var.f0, var.h);
            pa[i] = calculate_pa(u, f, var.c, var.tg_delta);

            printf("t=%.2fс: u=%.4fВ, f=%.4fГц, Pa=%.12fВт\n", t, u, f, pa[i]);
        }

        write_results("results.txt", time, pa, num_steps, v);
    }

    printf("Розрахунки завершено, збережено у файлі 'results.txt'\n");
    return 0;
}