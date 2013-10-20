#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAXN = 55;
const int MAXM = 10;

double p[MAXN], dp[MAXM][MAXN];
int n, k;

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n - 1; i++)
            scanf("%lf", &p[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][k] = 1;
        for (int i = 1; i < MAXM; i++) {
            for (int j = 1; j <= n; j++) {
                int l = j - 1;
                int r = j % n + 1;
                dp[i][j] = dp[i-1][l] * p[l];
                if (r != n)
                    dp[i][j] += dp[i-1][r] * (1 - p[r]);
            }
            dp[i][n] += dp[i-1][n];
            printf("dp[%d][%d] = %lf\n", i, n, dp[i][n]);
        }
        printf("%.10lf\n", 1 - dp[MAXM-1][n]);
    }
    return 0;
}
