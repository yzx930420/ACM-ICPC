#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d:\n", cas);
        puts("*------------*");
        n /= 10;
        for (int i = 0; i < 10 - n; i++)
            puts("|............|");
        for (int i = 0; i < n; i++)
            puts("|------------|");
        puts("*------------*");

    }
    return 0;
}
