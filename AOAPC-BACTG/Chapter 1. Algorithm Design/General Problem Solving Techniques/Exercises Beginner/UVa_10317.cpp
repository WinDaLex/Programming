// UVa 10317
// Equating Equations
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 18;

vector<int> num(MAXN);
vector<char> opt(MAXN);
int sign[MAXN];
int num_pos;
bool got;

void init() {
    got = false;
    num_pos = 1;
    opt.clear();
    num.clear();
}

bool read() {
    init();

    bool bo = false;
    int tmp = 0;
    char ch;
    while ((ch = getchar()) && ch != '\n') {
        if (ch == EOF) return false;
        if (isspace(ch)) continue;
        if (isdigit(ch)) {
            tmp = tmp * 10 + (ch - '0');
            continue;
        }
        opt.push_back(ch);
        num.push_back(tmp);
        tmp = 0;
        if (bo ^ ch == '+') num_pos++;
        if (ch == '=') bo = true;
    }
    num.push_back(tmp);

    return true;
}

bool check() {
    int sum = 0;
    for (int i = 0; i < num.size(); i++)
        sum += sign[i] * num[i];
    return !sum;
}

void write() {
    int p = 0, q = 0;
    for (int i = 0; i < num.size(); i++)
        if (sign[i] == 1) swap(num[q++], num[i]);

    printf("%d", num[p++]);

    bool bo = false;
    for (int i = 0; i < opt.size(); i++) {
        printf(" %c", opt[i]);
        if (opt[i] == '=') {
            bo = true;
            printf(" %d", num[q++]);
        }
        else if (bo ^ opt[i] == '+') printf(" %d", num[p++]);
        else printf(" %d", num[q++]);
    }
    printf("\n");
    got = true;
}

void search(int x, int y) {
    if (got) return;
    if (x == num.size()) {
        if (y == num_pos && check()) write();
        return;
    }
    sign[x] = -1; search(x + 1, y);
    sign[x] = 1; search(x + 1, y + 1);
}

int main() {
    while (read()) {
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
            sum += num[i];
        if (sum % 2 == 0) search(0, 0);
        if (!got) puts("no solution");
    }

    return 0;
}
