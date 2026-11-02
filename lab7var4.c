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
    float buf;
    int a[Nmax], k, i, n, j, meth = 0;
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
    if (fscanf(fin, "%d", &meth) != 1 || meth < 0 || meth > 1) {
    printf("Введен некорректный номер способа сортировки(0 для пузырьковой, 1 для сортировки выбором)");
    fclose(fin);
    fclose(fout);
    return 1;
    }

    fprintf(fout, "Lab_7\n");
    // Вывод исходных данных
    fprintf(fout, "Кол-во элементов массива(n): %d\n", n);
    fprintf(fout, "Значения:\n");
    for(i=0; i<n; i++) fprintf(fout, "a%d: %f\n", i+1, a[i]);
    // Сортировка(макс в конец)
    if (meth == 0) {
        fprintf(fout, "Метод сортировки: пузырьком\n");
        //Пузырьком
        for (i=n-1; i>0; i--){
            for (j=0; i<j; j++) {
                if(a[j] > a[j + 1]) {
                    buf = a[j];
                    a[j] = a[j + 1];
                    a[j - 1] = buf;
                }
            }
            fprintf(fout, "\nШаг %d: \n", i + 1);
            for (k=0; k<n; k++) fprintf(fout, "%5.1f ", a[k]);
        }
    }
    else {
        fprintf(fout, "Метод сортировки: выбором\n");
        //Выбором
        for (i=n-1;i>-1;i--) {
            int mi = i;
            for (j=i-1;j>-1;j--) if (a[j] > a[mi]) mi = j;
            if (mi != i) {
                buf = a[i];
                a[i] = a[mi];
                a[mi] = buf;
            }
            fprintf(fout, "\nШаг %d: \n", i + 1);
            for (k=0; k<n; k++) fprintf(fout, "%5.1f ", a[k]);
        }
    }
    fprintf(fout, "\nГотово. Осортированный массив:\n");
    for (k=0; k<n; k++) fprintf(fout, "%5.1f ", a[k]);

    fclose(fin);
    fclose(fout);
    return 0;
}
