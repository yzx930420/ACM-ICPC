/*****************************
  * Author: @frank93
  * Date: 2013-10-21
  * State: Accepted
  *****************************/
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 1000010;

int n;
int cnt[5], pre[5];

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(pre, 0, sizeof(pre));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            pre[t]++;
        }

        for (int i = 1; i <= 4; i++)
            cnt[i] = pre[i];

        int t = min(cnt[1], cnt[2]);
        cnt[3] += t;
        cnt[1] -= t;
        cnt[2] -= t;
        ans += t;

        if (cnt[1]) {
            cnt[3] += cnt[1] / 3;
            ans += cnt[1] / 3 * 2;
            cnt[1] %= 3;
            if (cnt[1] == 1) {
                if (cnt[3]) {
                    --cnt[3];
                    --cnt[1];
                    ++cnt[4];
                    ++ans;
                } else if (cnt[4] >= 2) {
                    cnt[4] -= 2;
                    --cnt[1];
                    cnt[3] += 3;
                    ans += 2;
                }
            } else if (cnt[1] == 2) {
                if (cnt[3] >= 2) {
                    cnt[3] -= 2;
                    cnt[1] -= 2;
                    cnt[4] += 2;
                    ans += 2;
                } else if (cnt[4]) {
                    --cnt[4];
                    cnt[3] += 2;
                    cnt[1] -= 2;
                    ans += 2;
                }
            }
        } else if (cnt[2]) {
            cnt[3] += cnt[2] / 3 * 2;
            ans += cnt[2] / 3 * 2;
            cnt[2] %= 3;

            if (cnt[2]) {
                if (cnt[2] == 1) {
                    if (cnt[4]) {
                        --cnt[4];
                        cnt[3] += 2;
                        --cnt[2];
                        ++ans;
                    } else if (cnt[3] >= 2) {
                        cnt[4] += 2;
                        cnt[3] -= 2;
                        --cnt[2];
                        ans += 2;
                    }
                } else if (cnt[2] == 2) {
                    cnt[2] -= 2;
                    cnt[4] += 1;
                    ans += 2;
                }

            }
        }

        if (cnt[1] + cnt[2]) {
            puts("-1");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
