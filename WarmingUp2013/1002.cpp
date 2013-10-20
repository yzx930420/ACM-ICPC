#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

const int MAXN = 310;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};

typedef Point Vector;

Point points[MAXN];
Vector v[MAXN];
int n;

int dcmp(double x, double y) {
    if (fabs(x - y) < 1e-7)
        return 0;
    else if (x < y)
        return -1;
    else
        return 1;
}

double xx(double x) {
    return x * x;
}

double get_dist(const Point& p1, const Point& p2) {
    return sqrt(xx(p1.x - p2.x) + xx(p1.y - p2.y));
}

double f(double t) {
    double dist = 0;
    //cout << "n = " << n << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
            Point p1(points[i].x + v[i].x * t, points[i].y + v[i].y * t);
            Point p2(points[j].x + v[j].x * t, points[j].y + v[j].y * t);
            dist = max(dist, get_dist(p1, p2));
            //printf("(%.0lf, %.0lf) (%.0lf %.0lf) %lf\n", p1.x, p1.y, p2.x, p2.y, get_dist(p1, p2));
            
        }
    return dist;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &points[i].x, &points[i].y);
            scanf("%lf %lf", &v[i].x, &v[i].y);
        }
        double l = 0, r = 1e10, m, mm;
        double ans1, ans2;
        while (dcmp(l, r) < 0) {
            m = (l + r) / 2;
            mm = (m + r) / 2;
            ans1 = f(m);
            ans2 = f(mm);
            if (ans1 < ans2)
                r = mm;
            else
                l = m;
        }
        //cout << f(0) << endl;
        printf("Case #%d: %.2lf %.2lf\n", cas, l, f(l));
    }
    return 0;
}
