template <typename T>
struct matrix {
    T e[MAXO][MAXO];
    int o;

    matrix(int ord) { memset(e, 0, sizeof(e)); o = ord; }

    matrix operator*(const matrix& one) {
        matrix res(o);
        for (int i = 0; i < o; i++)
            for (int j = 0; j < o; j++)
                for (int k = 0; k < o; k++)
                    res.e[i][j] += e[i][k] * one.e[k][j];
        return res;
    }

    matrix operator%(int mod) {
        for (int i = 0; i < o; i++)
            for (int j = 0; j < o; j++)
                e[i][j] %= mod;
        return *this;
    }
};
