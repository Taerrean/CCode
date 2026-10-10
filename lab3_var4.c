#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Nmax 20

int main() 
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    float x[Nmax], p, t, s = 0.0;
    int k = 0, n, i;
    printf("%40sLab_3\n");
    printf("Введите кол-во чисел(n): "); scanf("%d", &n);
            if (n < 1||n > 20) {
        printf("Некорректное количество чисел(1 <= n <= 20)");
        return 1;
    }
    printf("Введите точку отсчёта разницы величин(p): "); scanf("%f", &p);
        if (abs(p) > 10.0) {
        printf("Модуль точки отсчёта слишком большой(|p| <= 10)");
        return 1;
    }
    printf("Введите критическое удаление(t): "); scanf("%f", &t);
            if (t < 0||t > 20) {
        printf("Выбрано некорректное критическое удаление(0 < t <= 20)");
        return 1;
    }
    printf("Введите числовые значения(x):\n");
    for(i=0; i<n; i++) {
        scanf("%f", &x[i]);
        if (abs(x[i]) > 10.0) {
            printf("Модуль числа слишком большой(|x| <= 10)");
            return 1;
        }
    }

    printf("Кол-во значений(n): %d\n", n);
    printf("Точка отсчёта разницы величин(p): %5.1f\n", p);
    printf("Критическое удаление(t): %5.1f\n", t);
    printf("Значения:\n");
    for(i=0; i<n; i++) printf("x[%d]: %5.1f\n", i + 1, x[i]);

    for(i=0; i<n; i++) {
        if (abs(x[i] - p) <= t) {
            s += abs(x[i] - p);
            k++;
        } 
    }

    if (k == n) printf("Все значения отличаются от p не более, чем на t\n");
    else if (k == 0) printf("Нет точек, отличающихся от p не более, чем на t\n");
    else printf("Кол-во значений с разницей от p не меньше t = %d\n", k);

    if (s == 0.0) {
        if (k == 0) printf("Подходящих точек нет, невозможно посчитать сумму");
        else printf("Все значения совпадают с p\n");
    }
    else printf("Сумма разниц заданных значений и p = %5.1f\n", s);
    return 0;
}