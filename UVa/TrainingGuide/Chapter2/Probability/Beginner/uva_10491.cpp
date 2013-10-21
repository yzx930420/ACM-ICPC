#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a, b, c;
    double p1, p2;
    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        p1 = 1.0 * a / (a + b) * b / (a + b - c - 1);
        p2 = 1.0 * b / (a + b) * (b - 1) / (a + b - c - 1);
        printf("%.5lf\n", p1 + p2);
    }
    return 0;
}
