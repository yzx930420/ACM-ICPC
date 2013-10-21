#include<stdio.h>
#include<string.h>
#include<math.h>
const int MAXD = 35;
int N;
double T, q[MAXD];
void solve()
{
    int i, j, k;
    double eq, f = 1, quit;
    f = q[N];
    for(i = N - 1; i >= 0; i --)
    {
        quit = q[i];
        eq = quit / f;
        if(eq <= T)
            f = (T + 1) / 2 * f;
        else
            f = (eq - T) / (1 - T) * quit + (1 - eq) / (1 - T) * (eq + 1) / 2 * f;
    }
    printf("%.3lf\n", f);
}

int main()
{
    q[0] = 1;
    for(int i = 1; i <= 30; i ++)
        q[i] = 2 * q[i - 1];
    for(;;)
    {
        scanf("%d%lf", &N, &T);
        if(!N)
            break;
        if(fabs(1 - T) < 1e-9)
            printf("%.3lf\n", q[N]);
        else
            solve();
    }
    return 0;
}
