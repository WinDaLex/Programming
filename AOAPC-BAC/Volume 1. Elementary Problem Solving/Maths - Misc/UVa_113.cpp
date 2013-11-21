// UVa 113
// Power of Cryptography
// by A Code Rabbit

#include <cstdio>
#include <cmath>
using namespace std;

double N, P;

int main() {
    while (scanf("%lf%lf", &N, &P) == 2) {
        printf("%.0lf\n", pow(P, 1.0 / N));
    }

    return 0;
}
