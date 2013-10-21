#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;

const int MAXN = 70010;

int n, s;
int bag[MAXN], father[MAXN];

int main() {
    while (scanf("%d %d", &n, &s) != EOF) {
        map<int, int> cnt;
        memset(father, 0, sizeof(fa));
        LL sum = 0, left = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &bag[i]);
            cnt[bag[i]]++;
            sum += bag[i];
            father[i] = 0;
        }
        if (bag < s) {
            puts("-1");
            continue;
        } else if (bag == s) {
            for (int i = 0; i < n; i++)
                printf("%d %d\n", bag[i], 0);
            continue;
        }
        map<int, int>::iterator iter = cnt.end();
        iter--;
        if (iter->second == 1)
            cnt.erase(iter);
        else
            iter->second--;
        iter = cnt.end();
        iter--;

        dfs(0, iter, sum - s);

    }
    return 0;
}

bool dfs(int fa, map<int, int>::iterator iter, LL left) {
    if (iter == bag.end())
        return false;

    
}
