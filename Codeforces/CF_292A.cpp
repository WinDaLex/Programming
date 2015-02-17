// Codeforces #292 A
// Drazil and Date

#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, S;

int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    scanf("%d%d%d", &A, &B, &S);
    int d = S - (abs(A) + abs(B));
    puts(d >= 0 && d % 2 == 0 ? "Yes" : "No");

    return 0;
}
