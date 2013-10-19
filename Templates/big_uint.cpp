struct big_uint {
    int len, d[SIZE_UINT];

    // contructor and assignment
    big_uint() { memset(d, 0, sizeof(d)); len = 0; }
    big_uint(int num) { *this = num; }
    big_uint(const char* str) { *this = str; }

    void clean() { while (len > 1 && !d[len - 1]) len--; }
    big_uint operator=(int num) {
        char str[SIZE_UINT];
        sprintf(str, "%d", num);
        return *this = str;
    }
    big_uint operator=(const char* str) {
        memset(d, 0, sizeof(d));
        len = strlen(str);
        for (int i = 0; i < len; i++) d[i] = str[len - i - 1] - '0';
        clean();
        return *this;
    }

    // to string and overload iostream
    string to_str() const {
        string res = "";
        for (int i = 0; i < len; i++) res = (char)(d[i] + '0') + res;
        return res == "" ? "0" : res;
    }
    friend istream& operator>>(istream& is, big_uint& one) {
        string str;
        is >> str;
        one = str.c_str();
        return is;
    }
    friend ostream& operator<<(ostream& os, const big_uint& one) {
        os << one.to_str();
        return os;
    }

    // comparison operators
    bool operator<(const big_uint& rhs) const {
        if (len != rhs.len) return len < rhs.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != rhs.d[i]) return d[i] < rhs.d[i];
        return false;
    }
    bool operator>(const big_uint& rhs) const { return rhs < *this; }
    bool operator<=(const big_uint& rhs) const { return !(rhs < *this); }
    bool operator>=(const big_uint& rhs) const { return !(*this < rhs); }
    bool operator!=(const big_uint& rhs) const { return rhs < *this || *this < rhs; }
    bool operator==(const big_uint& rhs) const { return !(rhs < *this || *this < rhs); }

    // four arithmetic operations
    big_uint operator+(const big_uint& rhs) const {
        big_uint res;
        for (int i = 0, x = 0; i < max(len, rhs.len) + 1; i++) {
            int tmp = d[i] + rhs.d[i] + x;
            res.d[res.len++] = tmp % 10;
            x = tmp / 10;
        }
        res.clean();
        return res;
    }
    big_uint operator-(const big_uint& rhs) {
        big_uint res;
        for(int i = 0, x = 0; i < len; i++) {
            int tmp = d[i] - rhs.d[i] - x;
            if (tmp >= 0) x = 0;
            else x = 1, tmp += 10;
            res.d[res.len++] = tmp;
        }
        res.clean();
        return res;
    }
    big_uint operator*(const big_uint& rhs) {
        big_uint res;
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

    // Compound Assignment Operators
    big_uint operator+=(const big_uint& rhs) { return *this = *this + rhs; }
    big_uint operator*=(const big_uint& rhs) { return *this = *this * rhs; }
    big_uint operator-=(const big_uint& rhs) { return *this = *this - rhs; }
};
