// Codeforces #291 C
// Watto and Mechanism

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int LEN = 600002;
const ll MOD = 1000000000007ll;

int N, M;
char S[LEN];

vector<ll> v;

ll hash_val(char s[]) {
    ll res = 0;
    for (int i = 0; s[i]; i++)
        res = (res * 4 + (s[i] - 'a' + 1)) % MOD;
    return res;
}

bool check(char s[]) {
    ll val = hash_val(s), k = 1;
    int len = strlen(s);
    for (int j = len - 1; j >= 0; j--) {
        ll cur_val = ((val - (s[j] - 'a' + 1) * k) % MOD + MOD) % MOD;
        for (char c = 'a'; c <= 'c'; c++) {
            ll final_val = (cur_val + (c - 'a' + 1) * k) % MOD;
            if (c != s[j] && binary_search(v.begin(), v.end(), final_val)) return true;
        }
        k = (k * 4) % MOD;
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", S);
        v.push_back(hash_val(S));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < M; i++) {
        scanf("%s", S);
        puts(check(S) ? "YES" : "NO");
    }
}
