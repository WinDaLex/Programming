#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);
const double EPS = 1e-4;

int main() {

    double x0, y0, x1, y1, x2, y2;
    double a0, b0, c0, a1, b1, c1;
    double x, y;
    double k1, k2;

    int N;
    double R;

    scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &x1, &y1, &x2, &y2);

    a0 = 2 * (x1 - x0), b0 = 2 * (y1 - y0);
    c0 = x0 * x0 + y0 * y0 - x1 * x1 - y1 * y1;

    a1 = 2 * (x2 - x1), b1 = 2 * (y2 - y1);
    c1 = x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2;

    x = (b1 * c0 - b0 * c1) / (a1 * b0 - a0 * b1);
    y = (a1 * c0 - a0 * c1) / (a0 * b1 - a1 * b0);

    double a[3] = {atan2(y0 - y, x0 - x), atan2(y1 - y, x1 - x), atan2(y2 - y, x2 - x)};

    N = -1;
    for (int n = 3; n <= 100; n++) {
        bool bo = false;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (fabs(sin(n * (a[i] - a[j]) / 2)) > EPS)
                    bo = true;
        if (!bo) {
            N = n;
            break;
        }
    }

    double R2 = (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y);

    if (N < 0) puts("-1");
    else printf("%.6lf\n", 1.0 / 2 * N * sin(2 * PI / N) * R2);

    return 0;
}
