// 2013杭州邀请赛 J Mex

#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>

using namespace std;

typedef long long LL;
const int MAXN = 210010;

int n;
int next[MAXN], arr[MAXN], nx[MAXN], mex[MAXN];
bool vis[MAXN];

int main(){
    while (scanf("%d", &n), n) {
        memset(vis, 0, sizeof(vis));
        mex[0] = 0;

        LL ans = 0, s = 0;
        map<int, int> mp;

        int p = 0;
        nx[0] = n + 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] > n) arr[i] = n + 1;
            vis[arr[i]] = true;
            while (vis[p]) ++p;
            mex[i] = p;
            mp[i] = mex[i];
            s += mex[i];
            nx[i] = n + 1;
        }

        for (int i = n; i >= 1; i--) {
            next[i] = nx[arr[i]];
            nx[arr[i]] = i;
        }

        map<int, int>::iterator iter1, iter2;

        ans = s;
        for (int i = 1; i <= n - 1; i++) {
            if (!arr[i]) s--;
            mp[i] = -1;
            iter1 = mp.lower_bound(next[i] - 1);
            if (iter1->second >= arr[i]) {
                if (iter1->first >= next[i]) {
                    mp[next[i]-1] = iter1->second;
                    iter1--;
                }
                while (iter1->second >= arr[i]) {
                    LL l = iter1->second - arr[i];
                    s -= l * (iter1->first);
                    mp.erase(iter1--);
                    s += l * (iter1->first);
                }
                mp[next[i]-1] = arr[i];
            }
            ans += s;
        }
        cout << ans << endl;
    }
    return 0;
}

