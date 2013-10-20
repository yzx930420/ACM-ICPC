#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 1 << 21; 

struct Crood {
    int x, y;
    Crood (int x = 0, int y = 0): x(x), y(y) {}
};

typedef Crood Vector;

int n;
int fl[MAXN];
int dp[MAXN];
vector<int> square;
vector<Crood> vec;

Vector operator-(Crood a, Crood b) {
    return Vector(a.x - b.x, a.y - b.y);
}

int Dot(Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}

double Len(Vector v) {
    return sqrt(1.0 * v.x * v.x + 1.0 * v.y * v.y);
}

bool is_squ() {
    Crood p[4], t;
    Vector v[4];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (fl[i]) {
            p[cnt++] = vec[i];
        }
    v[0] = p[0] - p[1];
    v[1] = p[1] - p[2];
    v[2] = p[2] - p[3];
    v[3] = p[3] - p[0];
    if (!Dot(v[0], v[1]) && !Dot(v[1], v[2]) && !Dot(v[2], v[3])
            && Len(v[0]) == Len(v[1])
            && Len(v[1]) == Len(v[2])
            && Len(v[2]) == Len(v[3]))
        return true;

    t = p[1];
    p[1] = p[2];
    p[2] = t;
    v[0] = p[0] - p[1];
    v[1] = p[1] - p[2];
    v[2] = p[2] - p[3];
    v[3] = p[3] - p[0];
    if (!Dot(v[0], v[1]) && !Dot(v[1], v[2]) && !Dot(v[2], v[3])
            && Len(v[0]) == Len(v[1])
            && Len(v[1]) == Len(v[2])
            && Len(v[2]) == Len(v[3]))
        return true;
    t = p[3];
    p[3] = p[2];
    p[2] = t;
    v[0] = p[0] - p[1];
    v[1] = p[1] - p[2];
    v[2] = p[2] - p[3];
    v[3] = p[3] - p[0];
    if (!Dot(v[0], v[1]) && !Dot(v[1], v[2]) && !Dot(v[2], v[3])
            && Len(v[0]) == Len(v[1])
            && Len(v[1]) == Len(v[2])
            && Len(v[2]) == Len(v[3]))
        return true;
    return false;
}


void dfs(int ss, int step, int state) {
    if (step == 4) {
        bool ok = is_squ();
        if (ok) square.push_back(state);
        return;
    }
    if (ss >= n) return;
    for (int i = ss; i < n; i++) {
        fl[i] = true;
        dfs(i + 1, step + 1, state | (1 << i));
        fl[i] = false;
    }
}

int main() {
    while (scanf("%d", &n)) {
        if (n == -1)
            break;
        square.clear();
        vec.clear();
        memset(fl, 0, sizeof(fl));
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            vec.push_back(Crood(x, y));
        }
        if (n < 4) {
            printf("0\n");
            continue;
        }
        int total = (1 << n) - 1;
        for (int i = 0; i <= n - 4; i++) {
            fl[i] = true;
            dfs(i + 1, 1, 1 << i);
            fl[i] = false;
        }

        int size = square.size();
        for (int i = 0; i <= total; i++) {
            for (int j = 0; j < size; j++) {
                if ((square[j] & i) == 0){
                    dp[square[j] | i] = max(dp[square[j] | i], dp[i] + 4);
                }
            }
        }
        printf("%d\n", dp[total]);
    }

    return 0;
}
