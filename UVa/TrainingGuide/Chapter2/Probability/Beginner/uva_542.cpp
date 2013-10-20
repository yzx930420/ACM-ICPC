#include <stdio.h>
#include <string.h>

using namespace std;

const int MAX_LEN = 100;
const int N = 16;

char name[N][MAX_LEN];
double p[N][N];
double dp[N][6];

int main() {
    for (int i = 0; i < N; i++)
        scanf("%s", name[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%lf", &p[i][j]);
            p[i][j] /= 100;
        }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++)
        dp[i][0] = 1;
    int len = 1;
    for (int i = 1; i <= 4; i++, len *= 2)
        for (int j = 0; j < N; j++) {
            int t;
            if ((j / len) & 1) {
                t = (j / len - 1) * len;
            } else {
                t = (j / len + 1) * len;
            }
            for (int k = t; k < t + len; k++)
                dp[j][i] += dp[j][i-1] * dp[k][i-1] * p[j][k];
        }
    for (int i = 0; i < N; i++)
        printf("%-11sp=%.2lf%%\n", name[i], dp[i][4] * 100);
    return 0;
}
