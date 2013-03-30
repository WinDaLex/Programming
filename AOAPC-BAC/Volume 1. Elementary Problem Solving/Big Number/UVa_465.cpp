// UVa 465
// Overflow
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAXD = 10000;

struct BigUINT {
    int len, d[MAXD];

    BigUINT() { memset(d, 0, sizeof(d)); len = 0; }
    BigUINT(int num) { *this = num; }
    BigUINT(const char* str) { *this = str; }

    void clean() { while (len > 1 && !d[len - 1]) len--; }
    BigUINT operator=(int num) {
        char str[MAXD];
        sprintf(str, "%d", num);
        return *this = str;
    }
    BigUINT operator=(const char* str) {
        memset(d, 0, sizeof(d));
        len = strlen(str);
        for (int i = 0; i < len; i++) d[i] = str[len - i - 1] - '0';
        clean();
        return *this;
    }

    BigUINT operator+(const BigUINT& rhs) const {
        BigUINT res;
        for (int i = 0, x = 0; i < max(len, rhs.len) + 1; i++) {
            int tmp = d[i] + rhs.d[i] + x;
            res.d[res.len++] = tmp % 10;
            x = tmp / 10;
        }
        res.clean();
        return res;
    }
    BigUINT operator*(const BigUINT& rhs) {
        BigUINT res;
        res.len = len + rhs.len;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < rhs.len; j++)
                res.d[i + j] += d[i] * rhs.d[j];
        for(int i = 0; i < res.len - 1; i++) {
            res.d[i + 1] += res.d[i] / 10;
            res.d[i] %= 10;
        }
        res.clean();
        return res;
    }

    bool operator<(const BigUINT& rhs) const {
        if (len != rhs.len) return len < rhs.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != rhs.d[i]) return d[i] < rhs.d[i];
        return false;
    }
    bool operator>(const BigUINT& rhs) const { return rhs < *this; }
    bool operator<=(const BigUINT& rhs) const { return !(rhs < *this); }
    bool operator>=(const BigUINT& rhs) const { return !(*this < rhs); }
    bool operator!=(const BigUINT& rhs) const { return rhs < *this || *this < rhs; }
    bool operator==(const BigUINT& rhs) const { return !(rhs < *this || *this < rhs); }
};

char str_a[MAXD];
char str_b[MAXD];
char opt;
BigUINT A, B, ans;

int main() {
    while (scanf("%s %c %s", str_a, &opt, str_b) != EOF) {
        A = str_a; B = str_b;
        cout << str_a << " " << opt << " " << str_b << endl;
        if (A > numeric_limits<int>::max()) printf("first number too big\n");
        if (B > numeric_limits<int>::max()) printf("second number too big\n");
        ans = opt == '+' ? A + B : A * B;
        if (ans > numeric_limits<int>::max()) printf("result too big\n");
    }

    return 0;
} 
