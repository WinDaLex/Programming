// UVa 11752
// The Super Powers
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

typedef unsigned long long ULL;

const int prime[18] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

bool is_prime[65];

set<ULL> s;

int main() {
    for (int i = 0; i < 18; i++)
        is_prime[prime[i]] = true;

    for (int i = 2; i < (1 << 16); i++) {
        ULL x = i, a = i;
        for (int j = 2; j < ceil(64 * log(2) / log(i)); j++) {
            x *= i;
            if (!is_prime[j]) s.insert(x);
        }
    }

    puts("1");
    for (set<ULL>::iterator iter = s.begin(); iter != s.end(); iter++)
        printf("%llu\n", *iter);

    return 0;
}
