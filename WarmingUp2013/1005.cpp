#include <stdio.h>
#include <iostream>


using namespace std;

int x1, x2, x3, x4, y1, y2, y3, y4;
double D, E, F;

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d %d", &x1, &y1);
        scanf("%d %d", &x2, &y2);
        scanf("%d %d", &x3, &y3);
        scanf("%d %d", &x4, &y4);
        D = 1.0 * ((y1 - y3) * (x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) - (y1 - y2) * (x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3)) / ((x1 - x3) * (y1 - y3) - (x1 - x3) * (y1 - y2));
        E = 1.0 * ((x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) + D * (x1 - x2)) ;// (y2 - y1);
        cout << y2 << endl;
        cout << y1 << endl;
        F = -(x1 * x1 + y1 * y1 + D * x1 + E * y1);
        cout << D << " " << E << " " << F << endl;
        if (x4 * x4 + D * x4 + E * x4 + F > 0)
            printf("Case #%d: Safe\n", cas);
        else
            printf("Case #%d: Danger\n", cas);
    }
    return 0;
}
