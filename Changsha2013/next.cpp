#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    double p;
    int n;
    Node(double p = 0, int n = 0): p(p), n(n) {}
};

int gcd(int a, int b) {
    return b ? a : gcd(b, a % b);
}


int main() {
    int a, b, c, na, nb, nc, B, T;;
    scanf("%d", &T);
    map<int, Node> mp;

    while (T--) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &na, &nb, &nc, &B);
        double pa = 1.0 * (101 - a) / 101;
        double pb = 1.0 * (a - b) / 101;
        double pc = 1.0 * (b - c) / 101;
        int g = gcd(gcd(na, nb), nc);
        int mn = min(min(na, nb), nc);
        int mx = B - 1 + max(max(na, nb), nc);
        double ans = 0;
        mp[0] = Node(1, 1);
        map<int, Node>::iterator iter;
        while (iter->second.p) {

        }
        /*
        if(max(na, max(nb, nc)) >= B){
            
        }else{
            int cnt = 0;
            for (int i = B; i <= mx; i++) if (i % g == 0){
                double e = i / (pa * na + pb * nb + pc * nc);
                ans += e;
                cnt++;
            }
            ans /= cnt;
        }
        */
        printf("%.6lf\n", ans);
    }

    return 0;
}
