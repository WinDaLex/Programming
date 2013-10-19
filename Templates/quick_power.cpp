template <typename T>
T quick_power(T rdx, int exp, int mod) {
    T res = rdx %= mod;
    exp--;
    while (exp) {
        if (exp & 1) res = res * rdx % mod;
        exp >>= 1;
        rdx = rdx * rdx % mod;
    }
    return res;
}
