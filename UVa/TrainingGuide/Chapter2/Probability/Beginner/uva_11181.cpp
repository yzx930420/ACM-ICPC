#include<stdio.h>
#include<string.h>
const int MAXD = 25;
int N, R;
double ap[MAXD], p[MAXD];
void solve() {
    int i, j, k;
    double ans, rp = 0;
    for(i = 0; i < N; i ++)
        scanf("%lf", &p[i]);
    if(R == 0) {
        for(i = 0; i < N; i ++)
            printf("0.000000\n");
        return ;
    }
    memset(ap, 0, sizeof(ap));
    for(i = 0; i < (1 << N); i ++) {
        k = 0;
        for(j = 0; j < N; j ++)
            if((1 << j) & i)
                k ++;
        if(k == R) {
            ans = 1;
            for(j = 0; j < N; j ++) {
                if((1 << j) & i)
                    ans *= p[j];
                else
                    ans *= (1 - p[j]);
            }
            rp += ans;
            for(j = 0; j < N; j ++)
                if((1 << j) & i)
                    ap[j] += ans;
        }
    }
    for(i = 0; i < N; i ++)
        printf("%.6lf\n", ap[i] / rp);
}
int main() {
    int t = 0;
    while (1) {
        scanf("%d%d", &N, &R);
        if(!N && !R)
            break;
        printf("Case %d:\n", ++t);
        solve();
    }
    return 0;
}
