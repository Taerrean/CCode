#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define Nmax 20

void readMat(FILE *fin, FILE *fout, float mat[Nmax][Nmax], int *size, int *flag, char name) {
    int i, j;

    if (*flag) {
        if (fscanf(fin, "%d", size) != 1) {
            fprintf(fout, "Ошибка чтения размера матрицы %c.\n", name);
            *flag = 0;
        }
    }

    if (*flag) {
        if (*size < 1 || *size > Nmax) {
            fprintf(fout, "Недопустимый размер матрицы %c. Допустимый диапазон: от 1 до %d.\n", name, Nmax);
            *flag = 0;
        }
    }

    for (i = 0; i < *size && *flag; i++) {
        for (j = 0; j < *size && *flag; j++) {
            if (fscanf(fin, "%f", &mat[i][j]) != 1) {
                fprintf(fout, "Ошибка чтения элемента матрицы %c[%d][%d].\n", name, i + 1, j + 1);
                *flag = 0;
            }
        }
    }
}

void showMat(FILE *fout, float mat[Nmax][Nmax], int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fprintf(fout, "%g", mat[i][j]);
            if (j < size - 1) {
                fprintf(fout, "\t");
            }
        }
        fprintf(fout, "\n");
    }
}

void workMat(float mat[Nmax][Nmax], int size, float *sum) {
    int i, j;

    *sum = 0;

    for (i = 0; i < size; i++) {
        *sum += mat[i][i];
        for (j = i + 1; j < size; j++) {
            mat[i][j] = fabs(mat[i][j]);
        }
    }
}

void showRes(FILE *fout, float mat[Nmax][Nmax], int size, float *sum, char num) {
    workMat(mat, size, sum);
    fprintf(fout, "Матрица %c после замены отрицательных элементов выше главной диагонали:\n", num);
    showMat(fout, mat, size);
    fprintf(fout, "Сумма элементов главной диагонали матрицы %c = %g\n\n", num, *sum);
}

int main(int argc, char *argv[]) {
    FILE *fin = NULL;
    FILE *fout = NULL;
    float a[Nmax][Nmax], b[Nmax][Nmax], c[Nmax][Nmax];
    float sa = 0, sb = 0, sc = 0, min;
    int na = 0, nb = 0, nc = 0;
    int flag = 1;

    setlocale(LC_ALL, "Russian");

    if (argc != 3) {
        fprintf(stderr, "Запуск: %s <входной_файл> <выходной_файл>\n", argv[0]);
        flag = 0;
    }

    if (flag) {
        fout = fopen(argv[2], "w");
        if (fout == NULL) {
            fprintf(stderr, "Не удалось открыть выходной файл %s.\n", argv[2]);
            flag = 0;
        }
    }

    if (flag) {
        fin = fopen(argv[1], "r");
        if (fin == NULL) {
            fprintf(stderr, "Не удалось открыть входной файл %s.\n", argv[1]);
            flag = 0;
        }
    }

    if (flag) {
        readMat(fin, fout, a, &na, &flag, 'A');
        readMat(fin, fout, b, &nb, &flag, 'B');
        readMat(fin, fout, c, &nc, &flag, 'C');
    }

    if (flag) {
        fprintf(fout, "Lab_11\n");
        fprintf(fout, "Матрица A, размер %d x %d:\n", na, na);
        showMat(fout, a, na);
        fprintf(fout, "\nМатрица B, размер %d x %d:\n", nb, nb);
        showMat(fout, b, nb);
        fprintf(fout, "\nМатрица C, размер %d x %d:\n", nc, nc);
        showMat(fout, c, nc);
        fprintf(fout, "\nРезультаты обработки:\n");

        showRes(fout, a, na, &sa, 'A');
        showRes(fout, b, nb, &sb, 'B');
        showRes(fout, c, nc, &sc, 'C');

        min = fabs(sa);
        if (fabs(sb) < min) {
            min = fabs(sb);
        }
        if (fabs(sc) < min) {
            min = fabs(sc);
        }

        fprintf(fout, "Наименьший модуль суммы элементов главной диагонали = %g\n", min);
        fprintf(fout, "Матрицы с наименьшим модулем суммы элементов главной диагонали: ");

        if (fabs(sa) == min) {
            fprintf(fout, "A ");
        }
        if (fabs(sb) == min) {
            fprintf(fout, "B ");
        }
        if (fabs(sc) == min) {
            fprintf(fout, "C ");
        }
        fprintf(fout, "\n");
    }

    if (fin != NULL) {
        fclose(fin);
    }
    if (fout != NULL) {
        fclose(fout);
    }

    if (!flag) {
        fprintf(stderr, "Программа завершила работу с ошибкой.\n");
    }

    return 0;
}
