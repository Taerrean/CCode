#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define Nmax 20

int dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int n, r, i, s;
    float p, sr;
    float x[Nmax], y[Nmax];
    printf("%40s\n", "Lab_2");
    printf("Input dot number(n): "); scanf("%d", &n);
    printf("Input required distance(r): "); scanf("%d", &r);
    printf("Input dot coordinates(x, y): \n");
    for (i=0; i<n; i++)
    scanf("%f %f", &x[i], &y[i]);
    for (i=0; i<n; i++) {
        if (dist(0, 0, x[i], y[i]) > r && x[i] > 0 && y[i] > 0) {
            s = s + 1;
        }
        sr = sr + dist(0, 0, x[i], y[i]);
    }
    p = s/n;
    sr /= n;
    printf("Dot percentage = %.1f\n", p);
    printf("Avg. distance = %.4f\n", sr);
    return 0;
}