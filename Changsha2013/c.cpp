#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

char from[10], to[10];

/*
struct RGB {
    int r, g, b;
    RGB(int r = 0, int g = 0, int b = 0): r(r), g(g), b(b) {}
};

struct HSV {
    double h, s, v;
    HSV(double h = 0; h )
};

struct HSL {
    double h, s, l;
};
*/

void RGB2HSL(double r, double g, double b, double& h, double& s, double& l) {
    double mx = max(max(r, g), b);
    double mn = min(min(r, g), b);

    // h
    if (mx == mn) {
        h = 0;
    } else if (mx == r && g >= b) {
        h = 60.0 * (g - b) / (mx - mn);
    } else if (mx == r && g < b) {
        h = 60.0 * (g - b) / (mx - mn) + 360;
    } else if (mx == g) {
        h = 60.0 * (b - r) / (mx - mn) + 120;
    } else if (mx == b) {
        h = 60.0 * (r - g) / (mx - mn) + 240;
    }

    // l
    l = 0.5 * (mx + mn);

    // s
    if ((mx + mn) == 0 || mx == mn) {
        s = 0;
    } else if (mx + mn <= 1) {
        s = (mx - mn) / (2 * l);
    } else if (mx + mn >= 1) {
        s = (mx - mn) / (2 - 2 * l);
    }

}

void RGB2HSV(double r, double g, double b, double& h, double& s, double& v) {
    double mx = max(max(r, g), b);
    double mn = min(min(r, g), b);

    // h
    if (mx == mn) {
        h = 0;
    } else if (mx == r && g >= b) {
        h = 60.0 * (g - b) / (mx - mn);
    } else if (mx == r && g < b) {
        h = 60.0 * (g - b) / (mx - mn) + 360;
    } else if (mx == g) {
        h = 60.0 * (b - r) / (mx - mn) + 120;
    } else if (mx == b) {
        h = 60.0 * (r - g) / (mx - mn) + 240;
    }

    // s
    if (mx == 0) {
        s = 0;
    } else {
        s = 1.0 - (1.0 * mn / mx);
    }

    // v
    v = mx;
} 

void HSL2RGB(double h, double s, double l, int& r, int& g, int& b) {
    /*
    if (l < 0.5) {
        q = l * (1 + s);
    } else {
        q = l + s - (l * s);
    }

    p = 2 * l - q;

    double hk = h / 360;
    double tr = hk + 1.0 / 3;
    double tg = hk;
    double tb = hk - 1.0 / 3;
    if (tc < 0) {
        tc = tc + 1.0;
    }
    */
    double c = (1 - fabs(2 * l - 1)) * s;
    double th = h / 60;
}
void HSV2RGB(double h, double s, double v, double& r, double& g, double& b) {
    /*
    int hi = h / 60;
    hi %= 6;
    double f = h / 60 - hi;
    double p = v * (1 - s);
    double q = v * (1 - f * s);
    double t = v * (1 - (1 - f) * s);
    switch(hi) {
        case 0:
            r = v, g = t, b = p;
            break;
        case 1:
            r = q, g = v, b = p;
            break;
        case 2:
            r = p; g = v; b = t;
            break;
        case 3:
            r = p; g = q; b = v;
            break;
        case 4:
            r = t; g = p; b = v;
            break;
        case 5:
            r = v; g = p; b = q;
            break;
    }
    */
    double c = v * s;
    int th = h / 60;
    //printf("c = %lf\n", c);
    double x = c * (1 - fabs((th % 2 - 1) * 1.0));
    switch(th) {
        case 0: 
            r = c; g = x; b = 0;
            break;
        case 1:
            r = x; g = c; b = 0;
            break;
        case 2:
            r = 0; g = c; b = x;
            break;
        case 3:
            r = 0; g = x; b = c;
            break;
        case 4:
            r = x; g = 0; b = c;
            break;
        case 5:
            r = c; g = 0; b = x;
            break;
    }
    double m = v - c;
    r += m;
    g += m;
    b += m;
}
double Hue2RGB(double v1, double v2, double vH)
{
    if (vH < 0) vH += 1;
    if (vH > 1) vH -= 1;
    if (6.0 * vH < 1) return v1 + (v2 - v1) * 6.0 * vH;
    if (2.0 * vH < 1) return v2;
    if (3.0 * vH < 2) return v1 + (v2 - v1) * ((2.0 / 3.0) - vH) * 6.0;
    return (v1);
}


void HSL2RGB2(double H,double S,double L, double& R, double& G, double& B)
{
    //double R,G,B;
    double var_1, var_2;
    if (S == 0)                       //HSL values = 0 ÷ 1
    {
        R = L;                   //RGB results = 0 ÷ 255
        G = L;
        B = L;
    }
    else
    {
        if (L < 0.5) var_2 = L * (1 + S);
        else         var_2 = (L + S) - (S * L);

        var_1 = 2.0 * L - var_2;

        R = 1.0 * Hue2RGB(var_1, var_2, H + (1.0 / 3.0));
        G = 1.0 * Hue2RGB(var_1, var_2, H);
        B = 1.0 * Hue2RGB(var_1, var_2, H - (1.0 / 3.0));
    }
}
int main() {
    /*
       while (scanf("%s", to) != EOF) {
       double r, g, b;
       double h, s_hsl, s_hsv, l, v;
       scanf("%s", from);
       printf("to = %s   from = %s\n", to, from);
       if (strcmp(from, "RGB") == 0) {
       scanf("%lf %lf %lf", &r, &g, &b);
       r /= 255;
       g /= 255;
       b /= 255;
       if (strcmp(to, "HSL") == 0) { // RGB TO HSL
       RGB2HSL(r, g, b, h, s_hsl, l);
       printf("HSL %d %d%% %d%%\n", (int)(h + 0.5), (int)(s_hsl * 100 + 0.5), (int)(l * 100 + 0.5));

       } else if (strcmp(to, "HSV") == 0) {
       RGB2HSV(r, g, b, h, s_hsv, v);
       printf("HSV %d %d%% %d%%\n", (int)(h + 0.5), (int)(s_hsv * 100  + 0.5), (int)(v * 100 + 0.5));
       }

       } else if (strcmp(from, "HSL") == 0) { 
    //scanf("%d %d%% %d%%", &h, &s_hsl, &l);

    } else if (strcmp(from, "HSV") == 0) {
    scanf("%lf %lf%% %lf%%", &h, &s_hsv, &v);
    s_hsv /= 100;
    v /= 100;
    if (strcmp(to, "RGB") == 0) {
    HSV2RGB(h, s_hsv, v, r, g, b);
    r = r * 255 + 0.5;
    g = g * 255 + 0.5;
    b = b * 255 + 0.5;
    printf("RGB %d %d %d\n", (int)r, (int)g, (int)b);
    }
    }

    }
     */
    double r, g, b, h = 324, s_hsv = 56.0 / 100, s_hsl, v = 71, l;
    HSV2RGB(h, s_hsv, v, r, g, b);
    //RGB2HSV(r, g, b, h, s_hsv, v);
    //s_hsv = s_hsv * 100 + 0.5;
    //v = v * 100 + 0.5;
    //r = r * 255 + 0.5;
    //g = g * 255 + 0.5;
    //b = b * 255 + 0.5;
    //printf("RGB %d %d%% %d%%\n", (int)r, (int)g, (int)b);
    RGB2HSL(174.0/255,82.0/255,144.0/255, h, s_hsl, l);
    h = h + 0.5;
    s_hsl = s_hsl * 100 + 0.5;
    l = l * 100 + 0.5;

    printf("HSV %d %d%% %d%%\n", (int)h, (int)s_hsl, (int)l);
    return 0;
}

