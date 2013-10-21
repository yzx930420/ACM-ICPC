#include <stdio.h>
#include <string.h>

using namespace std;

int cnt1[11], cnt2[11];
char buf[1000100];

int main () {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        scanf("%s", buf);
        int len = strlen(buf);
        for (int i = 0; i < len; i++)
            cnt1[buf[i]-'0']++;
        scanf("%s", buf);
        for (int i = 0; i < len; i++)
            cnt2[buf[i]-'0']++;

        printf("Case #%d: ", cas);
        bool ok = false;
        for (int k = 9; !ok && k >= 1; k--) {
            for (int i = 1; !ok && i <= 9; i++)
                for (int j = 1; !ok && j <= 9; j++) {
                    if (cnt1[i] && cnt2[j] && (i + j) % 10 == k) {
                        cnt1[i]--;
                        cnt2[j]--;
                        printf("%d", k);
                        ok = true;
                    }
                }
        }
        if (!ok) {
            printf("0\n");
            continue;
        }



        for (int k = 9; k >= 0; k--) {
            for (int i = 0; i <= 9; i++)
                for (int j = 0; j <= 9; j++) {
                    while (cnt1[i] && cnt2[j] && (i + j) % 10 == k) {
                        cnt1[i]--;
                        cnt2[j]--;
                        printf("%d", k);
                    }
                }
        }
        printf("\n");

    }
    return 0;
}
