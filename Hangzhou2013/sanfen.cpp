#include <stdio.h>
#include <math.h>

const double eps = 1e-9;

int dcmp(double a, double b) {
    if (fabs(a - b) < eps)
        return 0;
    if (a < b)
        return -1;
    return 1;
}

double get_val(double t){
}

double sanfen(double l, double r) {
    //先减后增求最小
    while (dcmp(l, r) != 0) {
        double m = (l + r) / 2;
        double mm = (m + r) / 2;
        double val_m = get_val(m) ;
        double val_mm = get_val(mm);
        if (val_m < val_mm)
            r = mm;
        else
            l = m;
    }

    return l;
}

int main(){
    int tt; 
    scanf("%d", &tt);
    while(tt--){

    }
    return 0;
}
