#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define Nmax 20

int main(void)
{
    setlocale(LC_ALL, "ru-Ru.UTF-8");

    float x[Nmax], p, t, s = 0.0, d, ax, sabs = 0.0;
    int k = 0, n, i;

    char in_name[256], out_name[256];
    FILE *fin, *fout;

    printf("Введите имя входного файла: ");
    if (scanf("%255s", in_name) != 1) {
        printf("Ошибка чтения имени входного файла.\n");
        return 1;
    }

    printf("Введите имя выходного файла: ");
    if (scanf("%255s", out_name) != 1) {
        printf("Ошибка чтения имени выходного файла.\n");
        return 1;
    }

    fin = fopen(in_name, "r");
    if (fin == NULL) {
        printf("Не удалось открыть входной файл %s.\n", in_name);
        return 1;
    }

    fout = fopen(out_name, "w+");
    if (fout == NULL) {
        printf("Не удалось открыть выходной файл %s.\n", out_name);
        fclose(fin);
        return 1;
    }

    if (fscanf(fin, "%d", &n) != 1) {
        fprintf(fout, "Ошибка: не удалось прочитать количество чисел n.\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    if (n < 1 || n > Nmax) {
        fprintf(fout, "Некорректное количество чисел (1 <= n <= %d)\n", Nmax);
        fclose(fin);
        fclose(fout);
        return 1;
    }

    if (fscanf(fin, "%f", &p) != 1) {
        fprintf(fout, "Ошибка: не удалось прочитать p.\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    if (p < 0 || p > 10.0) {
        fprintf(fout, "Некорректная точка отсчёта(0 < p < 10\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    if (fscanf(fin, "%f", &t) != 1) {
        fprintf(fout, "Ошибка: не удалось прочитать t.\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    if (t < 0.0 || t > 10.0) {
        fprintf(fout, "Выбрано некорректное критическое удаление (0 <= t <= 10)\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (fscanf(fin, "%f", &x[i]) != 1) {
            fprintf(fout, "Ошибка: не удалось прочитать x[%d].\n", i + 1);
            fclose(fin);
            fclose(fout);
            return 1;
        }

        if (x[i] < -10.0 || x[i] > 10.0) {
            fprintf(fout, "Модуль числа слишком большой (|x| <= 10)\n");
            fclose(fin);
            fclose(fout);
            return 1;
        }
    }

    fprintf(fout, "Lab_3\n");
    fprintf(fout, "Кол-во значений(n): %d\n", n);
    fprintf(fout, "Точка отсчёта разницы величин(p): %5.1f\n", p);
    fprintf(fout, "Критическое удаление(t): %5.1f\n", t);
    fprintf(fout, "Значения:\n");

    for (i = 0; i < n; i++) {
        fprintf(fout, "x[%d]: %5.1f\n", i + 1, x[i]);
    }

    for (i = 0; i < n; i++) {
        ax *= pow(-1, 1 + !(x < 0));
        if (ax - p < 0)
            d = p - ax;
        else
            d = ax - p;

        if (d <= t) {
            s += x[i];
            sabs += d;
            k++;
        }
    }

    if (k == n)
        fprintf(fout, "Все значения отличаются от p не более, чем на t\n");
    else if (k == 0)
        fprintf(fout, "Нет точек, отличающихся от p не более, чем на t\n");
    else
        fprintf(fout, "Кол-во значений с разницей от p не больше t = %d\n", k);

    if (s == 0.0) {
        if (k == 0)
            fprintf(fout, "Подходящих точек нет, невозможно посчитать сумму\n");
        else {
            if (sabs == 0)
            fprintf(fout, "Все значения совпадают с p\n");
            else fprintf(fout, "Сумма значений равна нулю(они скомпенсировались)");
    } 
        else {
        fprintf(fout, "Сумма разниц заданных значений и p = %5.1f\n", s);
    }

    fclose(fin);
    fclose(fout);

    printf("Ok. Result is in %s\n", out_name);

    return 0;
}
