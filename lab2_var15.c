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
    printf("Input point number: "); scanf("%d", &n);
    s = 0.0;
    k = 0;
    cond = n > 0 && n < 21;
    if (cond) {
        printf("Input point coordinates:\n");
        for (i=0; i<n; i++) {
            scanf("%f %f", &x[i], &y[i]);
            if (abs(x[i]) > 10.0||abs(y[i]) > 10.0){
                printf("Incorrect coordinates(|x| <= 10, |y| <= 10).");
                return 0;
            }
        }
        printf("%35sLab_2 \n");
        printf("Initial point number(n) = %d\n", n);
        printf("Point coordinates:\n");
        for (i=1; i < n + 1; i++)
        printf("x%d: %5.1f y%d: %5.1f\n", i, x[i - 1], i, y[i - 1]);
        if (n == 1) {
            if (y[0] > x[0])
            k++;
            printf("Not enough points to calculate distance. Returning condition for point: %d", k);
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
                printf("All points meet the condition.\n");
            }
            else {
                if (k == 0) {
                    printf("No point meet the condition.\n");
                }
                else
                printf("Number of points meeting condition = %d\n", k);
            }
            printf("Total distance from last point = %5.5lf\n", s);
        }
    }
    else {
        printf("%40sLab_2 \n");
        printf("Ineligible point amount(1<=n<=20)");
        }
    return 0;
}

