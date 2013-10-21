/********************
  * Author: @frank93
  * Date: 2013-10-21
  * State: Accepted
  *******************/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 1000010;

char s1[MAXN], s2[MAXN];
int cnt[MAXN][40];

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

int main() {
    LL n, m;
    while (scanf("%lld %lld", &n, &m) != EOF){
        memset(cnt, 0, sizeof(cnt));
        scanf("%s%s", s1, s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        LL g = gcd(len1, len2);
        LL l = lcm(len1, len2);
        for (int i = 0; i < len1; i++) {
            cnt[i % g][s1[i] - 'a']++;
        }

        LL ans = l;
        for (int i = 0; i < len2; i++) {
            ans -= cnt[i % g][s2[i] - 'a'];
        }
        ans *= n * ((LL)len1) / l;
        printf("%lld\n", ans);
    }
    return 0;
}
