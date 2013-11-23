#include <cstdio>
#include <algorithm>
using namespace std;

struct square {
    char letter;
    int digit;
} s, t;

int main() {
    scanf("%c%d%*c", &s.letter, &s.digit);
    scanf("%c%d%*c", &t.letter, &t.digit);

    int ans = max(abs(s.letter - t.letter), abs(s.digit - t.digit));
    int num_l = s.letter - t.letter;
    int num_r = t.letter - s.letter;
    int num_u = t.digit - s.digit;
    int num_d = s.digit - t.digit;

    printf("%d\n", ans);
    for (int i = 0; i < ans; i++) {
        if (num_l-- > 0) putchar('L');
        if (num_r-- > 0) putchar('R');
        if (num_u-- > 0) putchar('U');
        if (num_d-- > 0) putchar('D');
        putchar('\n');
    }

	return 0;
}
