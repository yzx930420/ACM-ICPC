#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef _int64 LL;
const int MAXN = 300010;

char str[MAXN];
int r[MAXN];

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

struct SuffixArray{
    int wa[MAXN];
    int wb[MAXN];
    int wv[MAXN];
    int ws[MAXN];

    int sa[MAXN];
    int rank[MAXN];
    int height[MAXN];
    int r[MAXN];

    int n, m;

    void input(int *val, int len, int Max){
        for (int i = 0;i < len;i++)
            r[i] = val[i];
        r[len] = 0;
        n = len;
        m = Max;
        dc3(r, sa, n + 1, m);
        calHeight(r, sa, n);
    }

    int c0(int *r,int a,int b){
        return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
    }

    int c12(int k,int *r,int a,int b){
        if(k==2)
            return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
        else
            return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
    }

    void sort(int *r,int *a,int *b,int n,int m)
    {
        int i;
        for(i=0;i<n;i++) wv[i]=r[a[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
    }
    void dc3(int *r,int *sa,int n,int m)
    {
        int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
        r[n]=r[n+1]=0;
        for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
        sort(r+2,wa,wb,tbc,m);
        sort(r+1,wb,wa,tbc,m);
        sort(r,wa,wb,tbc,m);
        for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
            rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
        if(p<tbc) dc3(rn,san,tbc,p);
        else for(i=0;i<tbc;i++) san[rn[i]]=i;
        for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
        if(n%3==1) wb[ta++]=n-1;
        sort(r,wb,wa,ta,m);
        for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
        for(i=0,j=0,p=0;i<ta && j<tbc;p++)
            sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
        for(;i<ta;p++) sa[p]=wa[i++];
        for(;j<tbc;p++) sa[p]=wb[j++];
    }

    void calHeight(int *r,int *sa,int n)
    {
        int i,j,k=0;
        for(i=1;i<=n;i++) rank[sa[i]]=i;
        for(i=0;i<n;height[rank[i++]]=k)
            for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    }
    int Log[MAXN];
    int best[20][MAXN];
    void initRMQ() {             //初始化RMQ 标准RMQ 预处理O(nlgn)
        Log[0] = -1;
        for(int i = 1;i <= MAXN;i++){
            Log[i]=(i & (i - 1))?Log[i - 1] : Log[i - 1] + 1 ;
        }
        for(int i = 1; i <= n ; i ++) best[0][i] = height[i];
        for(int i = 1; i <= Log[n] ; i ++) {
            int limit = n - (1<<i) + 1;
            for(int j = 1; j <= limit ; j ++) {
                best[i][j] = (best[i-1][j] > best[i-1][j+(1<<i>>1)]) ? best[i-1][j+(1<<i>>1)] : best[i-1][j];
            }
        }
    }
    int lcp(int a,int b) {       //询问suffix[a]于suffix[b]的最长公共前缀(标准RMQ  询问O(1))  使用这个函数之前要先后调用initRMQ()和input()
        a = rank[a];    b = rank[b];
        if(a > b){
            int t = a;
            a = b;
            b = t;
        }
        a ++;
        int t = Log[b - a + 1];
        return (best[t][a] > best[t][b - (1<<t) + 1])? best[t][b - (1<<t) + 1] : best[t][a];
    }
}SA;

void init(char * str, int * r){
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        r[i] = str[i] - 'a' + 1;
    SA.input(r, len, 30);
    SA.initRMQ();
}

int lcp(int a1, int b1, int a2, int b2){
    int len = 0;
    int len1 = b1 - a1;
    int len2 = b2 - a2;
    if(a1 == a2){
        len = len1 < len2 ? len1 :len2;
    }else{
        len = SA.lcp(a1, a2);
        if(len > len1) len = len1;
        if(len > len2) len = len2;
    }
    return len;
}


int main() {
    while (scanf("%s", str) != EOF) {
        init(str, r);
        int n;
        int a1, b1;
        scanf("%d", &n);
        scanf("%d %d", &a1, &b1);
        LL pre = 0, after = 0;
        pre = b1 - a1 + 1;
        after = pre + 2;
        for (int i = 2; i <= n; i++) {
            char tmp[20];
            int a2, b2;
            scanf("%d %d", &a2, &b2);
            pre += b2 - a2 + 1;
            int len = lcp(a1, b1, a2, b2);
            sprintf(tmp, "%d", len);
            after += b2 - a2 - len + strlen(tmp) + 2;
            a1 = a2;
            b1 = b2;
        }
        cout << pre << " " << after << endl;
    }

    return 0;
}
