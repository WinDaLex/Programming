// UVa 10106
// Product
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAXD = 502;

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
    friend istream& operator>>(istream &in, BigUINT& one) {
        string str;
        in >> str;
        one = str.c_str();
        return in;
    }
    friend ostream& operator<<(ostream &out, const BigUINT& one) {
        out << one.to_str();
        return out;
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
};

BigUINT A, B;

int main() {
    while (cin >> A >> B) {
        cout << A * B << endl;
    }

    return 0;
}
