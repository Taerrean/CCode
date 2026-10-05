#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#define Nmax 20

double dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    setlocale(LC_ALL, "");
    int n, k, i, cond;
    double s;
    float x[Nmax], y[Nmax];
    FILE *f = fopen("testdata.txt", "r");
    if (f == NULL){
        printf("Ошибка. Файла не существует.");
        return 1;
    }
    printf("                   Lab_2 \n");
    n = fscanf(f, "%d", &n);
    printf("Получено кол-во заданных точек(%d).\n", n);
    s = 0.0;
    k = 0;
    cond = n > 0 && n < 21;
    if (cond) {
        for (i=0; i<n; i++) {
            fscanf(f, "%f %f", &x[i], &y[i]);
            if (x[i] == 0||y[i] == 0){
                printf("Введены пустые координаты.");
                return 1;
            }
            if (abs(x[i] > 10)||abs(y[i] > 10)) {
                printf("Некорректные координаты(|x| <= 10, |y| <= 10)");
                return 1;
            }
        }
        printf("Координаты точек:\n");
        for (i=1; i < n + 1; i++)
        printf("x%d: %5.1f y%d: %5.1f\n", i, x[i - 1], i, y[i - 1]);
        if (n == 1) {
            if (y[0] > x[0])
            k++;
            printf("Недостаточно координат для вычисления суммы расстояний(s). Соответствие точки условию: %d", k);
        }
        else {
            for (i=0; i<n-1; i++){
                s = s + dist(x[n - 1], y[n - 1], x[i], y[i]);
                if (y[i] > x[i])
                k++;
            }
            if (y[n - 1] > x[n - 1])
            k++;
            if (k == n) {
                printf("Все точки соответствуют условию.\n");
            }
            else {
                if (k == 0) {
                    printf("Нет точек, соответствующих условию.\n");
                }
                else
                printf("Кол-во точек, соответсвующих условию = %d\n", k);
            }
            printf("Сумма расстояний до последней точки = %5.5lf\n", s);
        }
    }
    else {
        printf("Некорректное кол-во точек(1<=n<=20)");
        }
    fclose(f);
    return 0;
}

