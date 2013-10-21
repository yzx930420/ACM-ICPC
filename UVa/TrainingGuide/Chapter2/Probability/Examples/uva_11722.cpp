#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

double Cross(Vector& A, Vector& B) {
    return A.x * B.y - A.y * B.x;
}

Vector operator-(Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}

double polygon_area(vector<Point>& polygon) {
    polygon.push_back(polygon[0]);
    int size = polygon.size();
    double sum = 0;
    for (int i = 0; i < size; i++) {
        Vector A = polygon[i];
        Vector B = polygon[i+1];
        sum += Cross(A, B);
    }
    return sum;
}

int main() {
    int t1, t2, s1, s2, w;
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d %d %d %d %d", &t1, &t2, &s1, &s2, &w);
        Point A(t1, s2), B(t1, s1), C(t2, s1), D(t2, s2);
        double x, y;
        double S = 0, S1 = 0, S2 = 0;
        double ta, tb, tc, td;
        double total = 1.0 * (t2 - t1) * (s2 - s1);
        vector<Point> polygon;
        Point P1(t1, t1 + w);
        Point Q1(s2 - w, s2);
        Point P2(t2, t2 + w);
        Point Q2(s1 - w, s1);
        Vector v1 = Q1 - P1;
        ta = Cross(A - D, P1 - D);
        tb = Cross(v1, B - P1);
        tc = Cross(v1, C - P1);
        td = Cross(C - B, P2 - B);

        if (ta <= 0) {
            S1 = 0;
        } else if (td <= 0) {
            S1 = total;
        } else if (tb >= 0 && tc >= 0) {
            x = s1 - w;
            y = t2 + w;
            S1 = total - (t2 - x) * (y - s1) / 2;
        } else if (tb <= 0 && tc <= 0) {
            x = s2 - w;
            y = t1 + w;
            S1 = (x - t1) * (s2 - y) / 2;
        } else if (tb > 0 && tc < 0) {

        } else if (tb < 0 && tc > 0) {
        }

        /*
        x = t1;
        y = x + w;
        if (y == s1) {
            polygon.push_back(B);
        } else if (y > s1) {
            polygon.push_back(Point(x, y));
        } else {
            polygon.push_back(Point(s1 - w, s1));
            polygon.push_back(B);
        }
        polygon.push_back(A);
        x = t2;
        y = x + w;
        if (y == s2) {
            polygon.push_back(D);
        } else if (y > s2) {
            polygon.push_back(Point(s2 - w, s2));
        } else {
            polygon.push_back(D);
            polygon.push_back(Point(x, y));
        }

        S += polygon_area(polygon);
        polygon.clear();

        x = t2;
        y = x - w;
        if (y == s2) {
            polygon.push_back(D);
        } else if (y > s2) {
            polygon.push_back(Point(s2 + w, s2));
            polygon.push_back(D);
        } else {
            polygon.push_back(Point(x, y));
        }
        polygon.push_back(C);
        x = t1;
        if (y == s1) {
            polygon.push_back(B);
        } else if (y > s1) {
            polygon.push_back(B);
            polygon.push_back(Point(x, y));
        } else {
            polygon.push_back(Point(s2 + w, s2));
        }

        S += polygon_area(polygon);
        */
        printf("Case #%d: %.8lf\n", cas, (total - S) / total);
    }
    return 0;
}

