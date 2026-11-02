#include <stdio.h>
#include <locale.h>
#define Nmax 20

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");

    int a[Nmax], k, i, n, j, meth = 0, buf;
    int flag = 1;
    FILE *fin = NULL, *fout = NULL;

    if (argc != 3) {
        fprintf(stderr, "Как запускать: %s <входной файл> <выходной файл>\n", argv[0]);
        flag = 0;
    }

    if (flag) {
        fin = fopen(argv[1], "r");
        if (fin == NULL) {
            printf("Не удалось открыть входной файл %s.\n", argv[1]);
            flag = 0;
        }
    }

    if (flag) {
        fout = fopen(argv[2], "w");
        if (fout == NULL) {
            printf("Не удалось открыть выходной файл %s.\n", argv[2]);
            flag = 0;
        }
    }

    if (flag) {
        if (fscanf(fin, "%d", &n) != 1 || n < 1 || n > Nmax) {
            printf("Введено некорректное значение количества элементов: 0 < n <= %d\n", Nmax);
            flag = 0;
        }
    }

    if (flag) {
        for (i = 0; i < n; i++) {
            if (fscanf(fin, "%d", &a[i]) != 1) {
                printf("Введено некорректное числовое значение a%d.\n", i + 1);
                flag = 0;
                break;
            }
        }
    }

    if (flag) {
        if (fscanf(fin, "%d", &meth) != 1 || meth < 0 || meth > 1) {
            printf("Введён некорректный номер способа сортировки: 0 — пузырьковая, 1 — выбором.\n");
            flag = 0;
        }
    }

    if (flag) {
        fprintf(fout, "Lab_7\n");
        fprintf(fout, "Кол-во элементов массива (n): %d\n", n);
        fprintf(fout, "Значения:\n");
        for (i = 0; i < n; i++)
            fprintf(fout, "a%d: %d\n", i + 1, a[i]);

        if (meth == 0) {
            fprintf(fout, "Метод сортировки: пузырьком\n");
            for (i = n - 1; i > 0; i--) {
                for (j = 0; j < i; j++) {
                    if (a[j] > a[j + 1]) {
                        buf = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = buf;
                    }
                }
                fprintf(fout, "\nШаг %d:\n", n - i);
                for (k = 0; k < n; k++)
                    fprintf(fout, "%d ", a[k]);
            }
        } else {
            fprintf(fout, "Метод сортировки: выбором\n");
            for (i = n - 1; i > 0; i--) {
                int mi = i;
                for (j = i - 1; j >= 0; j--) {
                    if (a[j] > a[mi])
                        mi = j;
                }
                if (mi != i) {
                    buf = a[i];
                    a[i] = a[mi];
                    a[mi] = buf;
                }
                fprintf(fout, "\nШаг %d:\n", n - i);
                for (k = 0; k < n; k++)
                    fprintf(fout, "%d ", a[k]);
            }
        }

        fprintf(fout, "\nГотово. Отсортированный массив:\n");
        for (k = 0; k < n; k++)
            fprintf(fout, "%d ", a[k]);
        fprintf(fout, "\n");
    }

    if (fin)
        fclose(fin);
    if (fout)
        fclose(fout);

    return 0;
}
```
