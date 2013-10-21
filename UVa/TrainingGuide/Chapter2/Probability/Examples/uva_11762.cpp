#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 1e6 + 10;

int prime[MAXN], fl[MAXN], cnt_prime = 0;
double f[MAXN];

void get_prime(int x) {
    memset(fl, 0, sizeof(fl));
    for (int i = 2; i < MAXN; i++) {
        if (!fl[i]) {
            prime[cnt_prime++] = i;
            for (int j = i * 2; j < MAXN; j += i)
                fl[j] = 1;
        }
    }
}

double get_f(int x) {
    if (x == 1)
        return f[x] = 0;
    if (f[x] != 0)
        return f[x];
    int cnt = 0, n;
    for (n = 0; n < cnt_prime && prime[n] <= x; n++)
        if (x % prime[n])
            ++cnt;
    f[x] = 1.0 * n / (n - cnt);
    for (int i = 0; i < cnt_prime && prime[i] <= x; i++)
        if (x % prime[i] == 0)
            f[x] += 1.0 / (n - cnt) * get_f(x / prime[i]);

    return f[x];
}

int main() {
    get_prime(MAXN);
    int T;
    scanf("%d", &T);
    memset(f, 0, sizeof(f));
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        int i, cnt = 0, t = 0;
        double ans = 0;
        printf("Case %d: %.10lf\n", cas, get_f(n));
    }
    return 0;
}
