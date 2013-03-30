// UVa 1339
// Ancient Cipher
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;

char str1[MAXN], str2[MAXN];

int cnt1[26], cnt2[26];

int main() {
    while (gets(str1)) {
        gets(str2);

        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 0; i < strlen(str1); i++) {
            cnt1[str1[i] - 'A']++;
            cnt2[str2[i] - 'A']++;
        }

        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);

        bool bo = true;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                bo = false;
                break;
            }
        }

        puts(bo ? "YES" : "NO");
    }
    

    return 0;
}
