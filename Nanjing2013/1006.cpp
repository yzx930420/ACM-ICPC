#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

struct Edge {
    int x, y;
    Edge (int x = 0, int y = 0) : x(x), y(y) {}
} all_edge[24] = {Edge(1, 2), Edge(2, 3), Edge(3, 4), Edge(5, 6), Edge(6, 7), Edge(7, 8), Edge(9, 10), Edge(10, 11), Edge(11, 12), Edge(13, 14), Edge(14, 15), Edge(15, 16), Edge(1, 5), Edge(5, 9), Edge(9, 13), Edge(2, 6), Edge(6, 10), Edge(10, 14), Edge(3, 7), Edge(7, 11), Edge(11, 15), Edge(4, 8), Edge(8, 12), Edge(12, 16)};

bool operator< (Edge a, Edge b){
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

bool operator== (Edge a, Edge b) {
    return a.x == b.x && a.y == b.y;
}

bool st[24];
bool fl[24];

set<Edge> ss;

int judge(int x, int y, set<Edge> s) {
    set<Edge>::iterator iter;
    int cnt = 0;
    if (x + 1 == y) {
        // heng
        if (x > 4) { 
            int ok = 0;
            // 不是第一行
            ok += s.count(Edge(x - 4, x));
            ok += s.count(Edge(x - 4, y - 4));
            ok += s.count(Edge(y - 4, y));
            if (ok == 3) cnt++;
        }
        if (x < 13) {
            int ok = 0;
            ok += s.count(Edge(x, x + 4));
            ok += s.count(Edge(x + 4, y + 4));
            ok += s.count(Edge(y, y + 4));
            if (ok == 3) cnt++;
        }
    } else if (x + 4 == y) {
        // shu
        if (x != 1 && x != 5 && x != 9) {
            // 不是第一列
            int ok = 0;
            ok += s.count(Edge(x - 1, x));
            ok += s.count(Edge(y - 1, y));
            ok += s.count(Edge(x - 1, y - 1));
            if (ok == 3) cnt++;
        }

        if (x != 4 && x != 8 && x != 12) {
            // 不是最后一行
            int ok = 0;
            ok += s.count(Edge(x + 1, x));
            ok += s.count(Edge(y + 1, y));
            ok += s.count(Edge(x + 1, y + 1));
            if (ok == 3) cnt++;
        }
    }
    return cnt;
}

int dfs(set<Edge> s, int x, int tom, int jerry, int step) {
    s.insert(all_edge[x]);
    if (step & 1){
        jerry += judge(all_edge[x].x, all_edge[x].y, s);
    } else {
        tom += judge(all_edge[x].x, all_edge[x].y, s);
    }
    if (tom >= 5)
        return 1;
    else if (jerry >= 5)
        return -1;
    if (step > 24)
        return 0;
    int ok = 1;
    for (int i = 0; i < 24; i++){
        //if (!s.count(all_edge[i])){
        if (!fl[i]){
            fl[i] = true;
            ok = dfs(s, i, tom, jerry, step + 1);
            //ok = dfs(i, tom, jerry, step + 1);
            fl[i] = false;
        }
        if (ok == 0)
            return 0;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int cas = 1; cas <= T; cas++) {
        int n, cnt_Tom = 0, cnt_Jerry = 0;
        ss.clear();
        memset(fl, 0, sizeof(fl));
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x > y) swap(x, y);
            int ok = judge(x, y, ss);
            if (i & 1) {
                // Jerry
                cnt_Jerry += ok;
            } else if (!(i & 1)) {
                // Tom
                cnt_Tom += ok;
            }
            Edge t = Edge(x, y);
            ss.insert(t);
            for (int j = 0; j < 24; j++){
                if (t == all_edge[j])
                    fl[j] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < 24; i++) {
            //if (!ss.count(all_edge[i]))
            if (!fl[i]){
                fl[i] = true;
                ans = dfs(ss, i, cnt_Tom, cnt_Jerry, n);
                fl[i] = false;
            }
            if (ans)
                break;
        }


        printf("Case #%d: ", cas);
        if (ans > 0)
            puts("Tom200");
        else {
            puts("Jerry404");
        }

    }

    return 0;
}
