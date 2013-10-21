
#include <iostream>
#include <stdio.h>
#include <string.h>
//#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;

typedef unsigned __int64 LL;

const LL MOD = 1e9 + 7;

struct Matrix {
    LL mat[7][7];
};


Matrix operator* (const Matrix& a, const Matrix& b) {
    Matrix c;
    memset(c.mat, 0, sizeof(c.mat));
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 7; k++) {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % MOD;
                c.mat[i][j] %= MOD;
            }

    return c;
}

Matrix quickPow(Matrix& matrix , LL k){
    Matrix ans;
    for(int i = 0 ; i < 7 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            if(i == j)
                ans.mat[i][j] = 1;
            else
                ans.mat[i][j] = 0;
        }
    }

    while(k){
        if(k % 2) 
            ans = ans*matrix;
        k /= 2;
        matrix = matrix*matrix;
    }
    return ans;
}

Matrix quick_pow(Matrix a, LL p) {
    if (p == 1)
        return a;
    Matrix t;
    t = quick_pow(a, p / 2);
    t = t * t;
    if (p & 1) t = t * a;
    return t;
}

int main() {
    LL n;
    LL a0, ax, ay, b0, bx, by;
    while (cin >> n) {
        cin >> a0 >> ax >> ay;
        cin >> b0 >> bx >> by;
        a0 %= MOD;
        b0 %= MOD;
        ax %= MOD;
        ay %= MOD;
        bx %= MOD;
        by %= MOD;
        if (!n) {
            puts("0");
            continue;
        }
        Matrix t;
        memset(t.mat, 0, sizeof(t.mat));
        t.mat[0][0] = ax;
        t.mat[0][4] = 1;
        t.mat[1][1] = bx;
        t.mat[1][5] = 1;
        t.mat[2][0] = ax * by % MOD;
        t.mat[2][1] = bx * ay % MOD;
        t.mat[2][2] = ax * bx % MOD;
        t.mat[2][6] = 1;
        t.mat[3][3] = 1;
        t.mat[3][2] = 1;
        t.mat[4][4] = 1;
        t.mat[5][5] = 1;
        t.mat[6][6] = 1;
        t = quickPow(t, n);
        LL ans = t.mat[3][0] * a0 % MOD;
        ans %= MOD;
        ans += t.mat[3][1] * b0 % MOD;
        ans %= MOD;
        ans += (t.mat[3][2] * a0 % MOD) * b0 % MOD;
        ans %= MOD;
        ans += t.mat[3][3] * 0 % MOD;
        ans %= MOD;
        ans +=  t.mat[3][4] * ay % MOD;
        ans %= MOD;
        ans += t.mat[3][5] * by % MOD;
        ans %= MOD;
        ans +=  (t.mat[3][6] * ay % MOD) * by % MOD;
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}
