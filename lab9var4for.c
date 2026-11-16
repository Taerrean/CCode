// Найти в целочисленной прямоугольной матрице первую строку, все элементы которой кратны 5.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Nmax 20
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");

    int x[Nmax][Nmax], i, n, k, j, fline = -1, flag = 1;
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
        if (fscanf(fin, "%d", &n) != 1) {
            fprintf(fout, "Некорректная запись кол-ва строк.\n");
            flag = 0;
        }
    }
    if (flag) {
        if (fscanf(fin, "%d", &k) != 1) {
            fprintf(fout, "Некорректная запись кол-ва столбцов.\n");
            flag = 0;
        }
    }
    if (flag) {
        for(i=0;i<n;i++)
        for(j=0;j<k;j++) {
            if (fscanf(fin, "%d", &x[i][j]) != 1) {
                fprintf(fout, "Некорректная запись элемента матрицы.\n");
                i = n;
                j = k;
                flag = 0;
            }
        }
    }
    if (flag) {
        fprintf(fout, "Lab_9 for\n");
        fprintf(fout, "Кол-во строк = %d, Кол-во столбцов = %d\n", n, k);
        fprintf(fout, "Матрица:\n");
        for (i=0; i<n; i++) {
            for (j=0; j<k; j++) {
                fprintf(fout, "%d ", x[i][j]);
            }
            fprintf(fout, "\n");
        }
        
        for (i=0; i<n; i++) {
            for(j=0; j<k && x[i][j] % 5 == 0; j++) {
            }
            if (j == k) {
                fline = i + 1;
                i = n;
            }
        }
        if (fline == -1) {
            fprintf(fout, "Нет строки, где все элементы кратны 5.\n");
        } else {
            fprintf(fout, "Номер первой строки, где все элементы кратны 5: %d\n", fline);
        }
    }
    if (fin) {
        fclose(fin);
    }
    if (fout) {
        fclose(fout);
    }
    printf("ok");
    return flag? 0 : 1;
}