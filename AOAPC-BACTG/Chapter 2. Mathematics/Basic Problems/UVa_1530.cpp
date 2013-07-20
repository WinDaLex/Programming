// UVa 1530
// Floating Point Numbers
// by A Code Rabbit

#include <cstdio>
#include <cmath>

char S[17];

double power2[128];
char ans[15];

int main() {
    power2[63] = 1.0;
    for (int i = 64; i < 128; i++)
        power2[i] = power2[i - 1] * 2;
    for (int i = 62; i >= 0; i--)
        power2[i] = power2[i + 1] / 2;

    puts("Program 6 by team X");

    while (gets(S)) {
        bool zero = true;
        for (int i = 1; i < 16; i++)
            if (S[i] == '1') zero = false;

        if (zero) {
            puts(" 0.000000e+000");
            continue;
        }
 
        int exp = 0;
        for (int i = 7; i > 0; i--)
            if (S[i] == '1')
                exp += power2[7 - i + 63];

        double man = 1;
        for (int i = 8; i < 16; i++)
            if (S[i] == '1')
                man += power2[7 - i + 63];

        sprintf(ans, "%13.6e\n", (S[0] == '1' ? -1 : 1) * man * power2[exp]);
        for (int i = 0; i < 11; i++) putchar(ans[i]);
        putchar('0');
        for (int i = 11; i < 13; i++) putchar(ans[i]);
        putchar('\n');
    }

    puts("End of program 6 by team X");

    return 0;
}
