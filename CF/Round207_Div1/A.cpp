/**************************
  * Author: @frank93
  * Date: 2013-10-21
  * State: Accepted
  ************************/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>

using namespace std;

const int MAXN = 300010;

int n, m;
int win[MAXN];

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        set<int> s;
        memset(win, 0, sizeof(win));
        for (int i = 1;  i<= n; i++)
            s.insert(i);
        for (int i = 1; i <= n; i++) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            set<int>::iterator iter = s.lower_bound(l);
            while (iter != s.end() && *iter <= r) {
                if (*iter != x) {
                    win[*iter] = x;
                    s.erase(iter++);
                } else
                    iter++;
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d", win[i]);
            if (n - i) printf(" ");
        }
        puts("");

    }
    return 0;
}
