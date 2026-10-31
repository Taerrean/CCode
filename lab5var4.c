#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Nmax 20

int main(int argc, char *argv[]) 
{
    setlocale(LC_ALL, "Russian");
    if (argc != 3) {
        fprintf(stderr, "Как запускать: %s <входной файл> <выходной файл>\n", argv[0]);
        return 1;
    }
    float a[Nmax], mins, s;
    int i, minm = 1, n;
    FILE *fin, *fout;
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Не удалось открыть входной файл %s.\n", argv[1]);
        return 1;
    }

    fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Не удалось открыть выходной файл %s.\n", argv[2]);
        fclose(fin);
        return 1;
    }

    if (fscanf(fin, "%d", &n) != 1 || n < 1 || n > Nmax) {
        printf("Введено некорректное значение элементов массива(0 < n <= %d)", Nmax);
        fclose(fin);
        fclose(fout);
        return 1;
    }
    for(i=0; i<n; i++) {
        if (fscanf(fin, "%f", &a[i]) != 1) {
            printf("Введено некорректное числовое значение a%d.", i + 1);
            fclose(fin);
            fclose(fout);
            return 1;
        }
    }
    mins = a[0];
    s = a[0];

    fprintf(fout, "Lab_4\n");
    // Вывод исходных данных
    fprintf(fout, "Кол-во элементов массива(n): %d\n", n);
    fprintf(fout, "Значения:\n");
    for(i=0; i<n; i++) fprintf(fout, "a%d: %f\n", i+1, a[i]);

    // Вычисление
    for(i=1; i<n; i++) {
        s += a[i];
        if (s < mins) {
            mins = s;
            minm = i + 1;
        }
    }
    if (n == 1) fprint(fout, "\nВведено только одно значение. Сумма = %5.2f, Номер = 1", a[0]);
    else {
        fprintf(fout, "\nНомер наименьшей суммы = %d\n", minm);
        fprintf(fout, "Наименьшая сумма = %5.1f", mins);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}