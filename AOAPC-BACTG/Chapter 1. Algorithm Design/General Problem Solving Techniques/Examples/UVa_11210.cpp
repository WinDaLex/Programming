// UVa 11210
// Mahjong
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LEN = 20;
const int SIZ = 34;
const int N = 14;

const char *map[] = {
    "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
    "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
    "1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
    "DONG", "NAN", "XI", "BEI",
    "ZHONG", "FA", "BAI"
};

char s[20];
int mj[N];

int cnt[SIZ];


int parse(char *s) {
    for (int i = 0; i < SIZ; i++)
        if (!strcmp(map[i], s)) return i;
    return -1;
}

bool search(int idx) {
    for (int i = 0; i < SIZ; i++) {
        if (cnt[i]) {
            if (cnt[i] >= 3) {
                cnt[i] -= 3;
                int ret = search(idx + 1);
                cnt[i] += 3;
                if (ret) return true;
            }
            if (i % 9 <= 6 && i < 27 && cnt[i + 1] && cnt[i + 2]) {
                cnt[i]--; cnt[i + 1]--; cnt[i + 2]--;
                int ret = search(idx + 1);
                cnt[i]++; cnt[i + 1]++; cnt[i + 2]++;
                if (ret) return true;
            }
            return false;
        }
    }
    return true;
}

bool check() {
    for (int i = 0; i < SIZ; i++) {
        if (cnt[i] >= 2) {
            cnt[i] -= 2;
            bool ret = search(0);
            cnt[i] += 2;
            if (ret) return true;
        }
    }
    return false;
}

int main() {
    int T = 0;
    while (scanf("%s", s) && s[0] != '0') {
        mj[0] = parse(s);
        for (int i = 1; i < N - 1; i++) {
            scanf("%s", s);
            mj[i] = parse(s);
        }

        printf("Case %d:", ++T);

        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < N - 1; j++)
            cnt[mj[j]]++;

        bool got = false;
        for (int i = 0; i < SIZ; i++) {
            if (cnt[i] >= 4) continue;
            cnt[i]++;
            if (check()) { got = true; printf(" %s", map[i]); }
            cnt[i]--;
        }

        if (!got) printf(" Not ready");
        printf("\n");
    }

    return 0;
}
