#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define Nmax 20

float dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int n, k, i, cond;
    float s;
    float x[Nmax], y[Nmax];
    printf("Input dot number: "); scanf("%d", &n);
    s = 0;
    k = 0;
    if (n >= 2) {
        printf("Input dot coordinates:\n");
        for (i=0; i<n; i++)
        scanf("%f %f", &x[i], &y[i]);
        printf("%f %f", x[n - 1], y[n - 1]);
        for (i=0; i<n-1; i++){
            s = s + dist(x[n - 1], y[n - 1], x[i], y[i]);
            if (y[i] > x[i])
            k = k + 1;
        }
        if (y[n - 1] > x[n - 1])
        k = k + 1;
        printf("Sought dots amount = %d\n", k);
        printf("Total distance from last dot = %f\n", s);
    } else {
        if (y[0] > x[0])
        k = k + 1;
        printf("Not enough dots to calculate distance. Returning condition alignment: %d", k);
    }
    return 0;
}
