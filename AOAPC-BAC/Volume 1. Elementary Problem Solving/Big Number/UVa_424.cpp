// UVa 424
// Integer Inquiry
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAXD = 1000;

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

    string to_str() const {
        string res = "";
        for (int i = 0; i < len; i++) res = (char)(d[i] + '0') + res;
        return res == "" ? "0" : res;
    }
    friend istream& operator>>(istream &in, BigUINT& x) {
        string str;
        in >> str;
        x = str.c_str();
        return in;
    }
    friend ostream& operator<<(ostream &out, const BigUINT& x) {
        out << x.to_str();
        return out;
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

    BigUINT operator+=(const BigUINT& rhs) { return *this = *this + rhs; }

    bool operator<(const BigUINT& rhs) const {
        if (len != rhs.len) return len < rhs.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != rhs.d[i]) return d[i] < rhs.d[i];
        return false;
    }
    bool operator!=(const BigUINT& rhs) const { return rhs < *this || *this < rhs; }
};

BigUINT ans;
BigUINT num;

int main() {
    ans = 0;
    while (cin >> num && num != 0) {
        ans += num;
    }
    cout << ans << endl;

    return 0;
}
