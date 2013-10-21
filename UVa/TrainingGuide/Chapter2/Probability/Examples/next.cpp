#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

const int MAXN = 33;

double expected[MAXN];

int main() {
    int n;
    double p;
    expected[0] = 1;
    while (scanf("%d %lf", &n, &p) != EOF) {
        if (n == 0 && p == 0)
            break;
        double p1 = p < 0.5 ? 0.5 - p: 0;
        double p2 = p < 0.5 ? 0.75 : ((p + 1) / 2);

        double ans = 1;
        double t = (1 - p - p1) / (1 - p) * p2 * 2;
        double now = t;
        printf("p1 = %lf p2 = %lf ", p1, p2);
        cout << "t = " << t << endl;
        for (int i = 1; i <= n; i++) {
            expected[i] = expected[i-1] * p1 / (1 - p) + now;
            ans = expected[i] > ans ? expected[i] : ans;
            now *= t;
            printf("%d %lf\n", i, now);
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}
