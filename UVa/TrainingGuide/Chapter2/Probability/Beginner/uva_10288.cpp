#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
    if (!a) return 1;
    LL c;
    while (b) {
        c = a;
        a = b;
        b = c % a;
    }
    return a;
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

void print_char(char c, int x) {
    for (int i = 0; i < x; i++) putchar(c);
}

struct Fraction {
    LL numerator;
    LL denominator;
    LL a;
    Fraction(LL num = 0, LL den = 1) : numerator(num % den), denominator(den), a(num / den) {}
    void print() {
        if (numerator) {
            char tmp[20];
            memset(tmp, 0, sizeof(tmp));
            sprintf(tmp, "%lld", a);
            int len1 = strlen(tmp);
            memset(tmp, 0, sizeof(tmp));
            sprintf(tmp, "%lld", denominator);
            int len2 = strlen(tmp);
            print_char(' ', len1 + 1);
            printf("%lld\n", numerator);
            printf("%lld ", a);
            print_char('-', len2);
            putchar('\n');
            print_char(' ', len1 + 1);
            printf("%lld\n", denominator);
        } else {
            printf("%lld\n", a);
        }
    }
};

Fraction operator+ (const Fraction& fa, const Fraction& fb) {
    LL t_a = fa.a + fb.a;
    LL t_den = lcm(fa.denominator, fb.denominator);
    LL t_num1 = t_den / fa.denominator * fa.numerator;
    LL t_num2 = t_den / fb.denominator * fb.numerator;
    LL t_num = (t_num1 + t_num2) % t_den;
    t_a += (t_num1 + t_num2) / t_den;
    LL g = gcd(t_num, t_den);
    t_num /= g;
    t_den /= g;
    return Fraction(t_a * t_den + t_num, t_den);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Fraction ans;
        for (int i = n; i > 0; i--) {
            ans = ans + Fraction(n, i);
        }

        ans.print();
    }
    return 0;
}
