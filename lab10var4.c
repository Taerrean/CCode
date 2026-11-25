//Задан целочисленный одномерный массив A из N элементов. Найти максимальное значение среди отрицательных элементов, расположенных до первого элемента, равного Т.
#include <stdio.h>
#include <locale.h>
#define Nmax 20

void findels(int n, int a[], int t, int *ft, int *fn) {
    int i;
    for (i=0; i<n; i++){
        if (a[i] == t && *ft == -1) *ft = i;
        if (a[i] < 0 && *fn == -1) *fn = i;
        if (*fn != -1 && *ft != -1) i = n;
    }
    return;
}

void findmaxneg(int a[], int *ft, int *fn) {
    int i;
    for (i=*fn + 1; i<*ft; i++) {
        if (a[i] < 0 && a[i] > a[*fn]) *fn = i;
    }
    return;
}

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "Russian");

    int i, a[Nmax], t, n, ft = -1, fn = -1, flag = 1, check = 1;
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
            fprintf(fout, "Некорректная запись кол-ва элементов массива(n).\n");
            flag = 0;
        }
    }
    if (flag) {
        if (fscanf(fin, "%d", &t) != 1) {
            fprintf(fout, "Некорректная запись искомого элемента-ограничителя(t).\n");
            flag = 0;
        }
    }
    if (flag) {
        for(i=0;i<n;i++) {
            if (fscanf(fin, "%d", &a[i]) != 1) {
                fprintf(fout, "Некорректная запись элемента массива(a[%d]).\n", i);
                i = n;
                flag = 0;
            }
        }
    }
    if (flag) {
        fprintf(fout, "Lab_10\n");
        fprintf(fout, "Кол-во элементов = %d\n", n);
        fprintf(fout, "Массив:\n");
        for (i=0; i<n; i++) {
            fprintf(fout, "a%d = %d ", i+1, a[i]);
        }
        fprintf(fout, "\n");

        findels(n, a, t, &ft, &fn);
        if (fn == -1) {
            fprintf(fout, "Поиск невозможен - не найдено отрицательных элементов.\n");
            check = 0;
        }
        if (ft == -1) {
            fprintf(fout, "Поиск невозможен - не найдено элементов, равных %d(t).\n", t);
            check = 0;
        }
        if (fn > ft) {
            fprintf(fout, "Поиск невозможен - первый отрицательный элемент массива находится после t(Номера: отр = %d, t = %d)\n", fn + 1, ft + 1);
            check = 0;
        }
        if (check) {
            findmaxneg(a, &ft, &fn);
            fprintf(fout, "Максимальный отрицательный элемент до первого, равного %d(t) равен %d\n", t, a[fn]);
        }
    }
    if (fin) fclose(fin);
    if (fout) fclose(fout);
    return 0;
}
