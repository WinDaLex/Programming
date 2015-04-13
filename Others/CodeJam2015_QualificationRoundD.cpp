// Google Code Jam 2015 Qualification Round D
// Ominous Omino

#include <cstdio>
#include <algorithm>
using namespace std;

int T, X, R, C;

bool check() {
    if (X >= 7) return false;
    if (R * C % X) return false;
    if (max(R, C) < X) return false;
    switch (X) {
        case 1: return true;
        case 2: return true;
        case 3: return max(R, C) >= 3 && min(R, C) >= 2;
        case 4: return max(R, C) >= 4 && min(R, C) >= 3;
        case 5: return (max(R, C) >= 5 && min(R, C) >= 3) && (max(R, C) != 5 || min(R, C) != 3);
        case 6: return max(R, C) >= 6 && min(R, C) >= 4;
        default: return false;
    }
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &X, &R, &C);
        printf("Case #%d: %s\n", cas, check() ? "GABRIEL" : "RICHARD");
    }

    return 0;
}
