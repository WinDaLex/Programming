namespace kmp {
    void get_fail(char* p, int* f) {
        int m = strlen(p);
        f[0] = f[1] = 0;
        for (int i = 1; i < m; i++) {
            int j = f[i];
            while (j && p[i] != p[j]) j = f[j];
            f[i + 1] = p[i] == p[j] ? j + 1 : 0;
        }
    }

    int go(char* t, char* p, int* f) {
        int n = strlen(t), m = strlen(p);
        get_fail(p, f);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j && p[j] != t[i]) j = f[j];
            if (t[i] == p[j]) j++;
            if (j == m) return i - m + 1;
        }
        return -1;
    }
}

// PS. f[] is useful, and it's important to explain something before all, f[x]
// means that it's about the xth char, not (x – 1)th char. In addition, if
// len % (len – f[len]) equals 0, means that there must be a repeating cycle
// whose length is (len – f[len]).
