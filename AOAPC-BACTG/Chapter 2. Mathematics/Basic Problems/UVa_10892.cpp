// UVa 10892
// LCM Cardinality
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int N;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    while (scanf("%d", &N) && N) {
        vector<int> divisor;
        for (int i = 1; i <= sqrt(N); i++) {
            if (N % i == 0) {
                divisor.push_back(i);
                if (N / i != i) divisor.push_back(N / i);
            }
        }

        int ans = 0;
        for (int i = 0; i < divisor.size(); i++)
            for (int j = i; j < divisor.size(); j++)
                if (lcm(divisor[i], divisor[j]) == N)
                    ans++;

        printf("%d %d\n", N, ans);
    }

    return 0;
}
