#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int MAXN = 100010;

double c[MAXN];
double jiecheng[MAXN];

void init() {
    jiecheng[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        jiecheng[i] = jiecheng[i-1] + log(i);
    }
}

double C(int n, int r) {
    return exp(jiecheng[n] - jiecheng[n-r] - jiecheng[r] + r * 2 * log(0.5));
}

int main() {
    int T;
    scanf("%d", &T);
    init();
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n == 2) {
            puts("0.0000");
            continue;
        }
        double ans = C(n - 2, n / 2 - 1);
        printf("%.4lf\n", 1 - ans);

    }
    return 0;
}
