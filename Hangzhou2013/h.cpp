#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int n;
int arr[MAXN], dp[MAXN][MAXN];

int solve() {
    int ans = 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][i] = 1;
    for (int i = n - 1; i > 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            if (arr[i] == arr[j])
                dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[1][i] + dp[i+1][n]);
    return ans;
}

int main() {
    while (scanf("%d", &n), n) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
