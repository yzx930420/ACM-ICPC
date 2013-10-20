#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double a, b, s;
        scanf("%lf %lf %lf", &a, &b, &s);
        if (s == 0) {
            puts("100.000000%");
            continue;
        }
        if (s >= a * b) {
            puts("0.000000%");
            continue;
        }
        double x = s / b;
        double s1 = s * (log(a) - log(x));
        s1 = (a - x) * b - s1;
        printf("%.6lf%%\n", 100 * s1 / a / b);
    }

    return 0;
}
