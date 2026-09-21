#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define Nmax 20

double dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int n, k, i, cond;
    double s;
    float x[Nmax], y[Nmax];
    printf("Input dot number: "); scanf("%d", &n);
    s = 0.0;
    k = 0;
    cond = n > 0 && n < 21;
    if (cond) {
        printf("Input dot coordinates:\n");
        for (i=0; i<n; i++)
        scanf("%f %f", &x[i], &y[i]);
        if (n == 1) {
            if (y[0] > x[0])
            k++;
            printf("Not enough dots to calculate distance. Returning condition for dot: %d", k);
        }
        else {
            for (i=0; i<n-1; i++){
                s = s + dist(x[n - 1], y[n - 1], x[i], y[i]);
                printf("%lf\n", s);
                if (y[i] > x[i])
                k++;
            }
            if (y[n - 1] > x[n - 1])
            k++;
            if (k == n) {
                printf("All dots meet the condition.\n");
            }
            else {
                if (k == 0) {
                    printf("No dots meet the condition.\n");
                }
                else
                printf("Sought dots amount = %d\n", k);
            }
            printf("Total distance from last dot = %lf\n", s);
        }
    }
    else {
        printf("Ineligible dot amount(1<=n<=20)");
        }
    return 0;
}

