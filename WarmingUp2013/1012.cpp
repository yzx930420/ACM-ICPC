#include <iostream>
#include <stdio.h>

typedef int LL;

using namespace std;

const int MAXN = 1e5 + 10;

LL n, arr[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int error_id = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for (int i = 2; i <= n; i++)
            if (arr[i] != arr[i-1] + 1) {
                error_id = i;
                break;
            }
        printf("Case #%d: %d\n", cas, error_id);
    }
    return 0;
}
