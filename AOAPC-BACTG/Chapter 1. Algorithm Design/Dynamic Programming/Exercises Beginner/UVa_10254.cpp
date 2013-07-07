// UVa 10254
// The Priest Mathematician
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 10002;
const int MAXD = 5002;

struct BigUnsigned {
    int len, d[MAXD];
    BigUnsigned() { memset(d, 0, sizeof(d)); len = 0; }
    BigUnsigned(int num) { *this = num; }
    BigUnsigned(const char *str) { *this = str; }
    void clean() { while (len > 1 && !d[len - 1]) len--; }
    BigUnsigned operator=(int num) {
        char str[MAXD];
        sprintf(str, "%d", num);
        *this = str;
        return *this;
    }
    BigUnsigned operator=(const char *str) {
        memset(d, 0, sizeof(d));
        len = strlen(str);
        for (int i = 0; i < len; i++) d[i] = str[len - i - 1] - '0';
        clean();
        return *this;
    }

    string to_str() const {
        string res = "";
        for (int i = 0; i < len; i++) res = (char)(d[i] + '0') + res;
        return res == "" ? "0" : res;
    }
    friend ostream &operator<<(ostream &out, const BigUnsigned &x) {
        out << x.to_str();
        return out;
    }

    bool operator<(const BigUnsigned &one) const {
        if (len != one.len) return len < one.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != one.d[i]) return d[i] < one.d[i];
        return false;
    }

    BigUnsigned operator+(const BigUnsigned &one) const {
        BigUnsigned res;
        for (int i = 0, x = 0; i < max(len, one.len) + 1; i++) {
            int tmp = d[i] + one.d[i] + x;
            res.d[res.len++] = tmp % 10;
            x = tmp / 10;
        }
        res.clean();
        return res;
    }

    BigUnsigned operator-(const BigUnsigned &one) const {
        BigUnsigned res;
        for (int i = 0, x = 0; i < len; i++) {
            int tmp = d[i] - one.d[i] - x;
            if (tmp >= 0) x = 0;
            else {
                x = 1;
                tmp += 10;
            }
            res.d[res.len++] = tmp;
        }
        res.clean();
        return res;
    }
};

int N;

BigUnsigned bin[MAXN];
BigUnsigned f[MAXN];

int main() {
    bin[0] = 1;
    for (int i = 1; i < MAXN; i++)
        bin[i] = bin[i - 1] + bin[i - 1];

    int last = 0;
    for (int i = 1; i < MAXN; i++) {
        f[i] = f[last] + f[last] + (bin[i - last] - 1);

        BigUnsigned tmp = f[last + 1] + f[last + 1] + (bin[i - (last + 1)] - 1);
        if (tmp < f[i]) {
            last++;
            f[i] = tmp;
        }
    }

    while (scanf("%d", &N) != EOF)
        cout << f[N] << endl;

    return 0;
}
