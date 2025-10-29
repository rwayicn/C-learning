#include <stdio.h>
#include <math.h>
#include <string.h>

static void fmt_real(double x, char *buf) {
    if (fabs(x) < 5e-10) x = 0.0;                       // 去掉负零
    double rx = round(x);
    if (fabs(rx - x) < 1e-9) {                         // 整数就不输出小数点
        sprintf(buf, "%.0f", rx);
    } else {                                           // 非整数保留5位小数并去掉末尾多余的0
        char tmp[64];
        sprintf(tmp, "%.5f", x);
        int len = strlen(tmp);
        while (len > 0 && tmp[len-1] == '0') tmp[--len] = '\0';
        if (len > 0 && tmp[len-1] == '.') tmp[--len] = '\0';
        strcpy(buf, tmp);
    }
}

int main() {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 0;

    if (fabs(a) < 1e-12) {
        if (fabs(b) < 1e-12) {
            // a==0 且 b==0 -> 非方程（样例中这样输出）
            printf("Not an equation.\n");
        } else {
            double x = -c / b;
            char sx[64];
            fmt_real(x, sx);
            printf("x=%s\n", sx);
        }
        return 0;
    }

    double D = b*b - 4*a*c;
    if (D > 1e-12) {
        double sd = sqrt(D);
        double x1 = (-b + sd) / (2*a);
        double x2 = (-b - sd) / (2*a);
        char s1[64], s2[64];
        fmt_real(x1, s1);
        fmt_real(x2, s2);
        printf("x1=%s x2=%s\n", s1, s2);
    } else if (fabs(D) <= 1e-12) {
        double x = -b / (2*a);
        char sx[64];
        fmt_real(x, sx);
        printf("x1=%s x2=%s\n", sx, sx);
    } else {
        double real = -b / (2*a);
        double imag = sqrt(-D) / (2 * fabs(a)); // imag 输出为正数，符号用 +/- 表示
        char sreal[64], simag[64];
        fmt_real(real, sreal);
        // 虚部按题目样例保留5位小数（不去掉末尾0）
        sprintf(simag, "%.5f", imag);
        printf("x1=%s+%si x2=%s-%si\n", sreal, simag, sreal, simag);
    }

    return 0;
}