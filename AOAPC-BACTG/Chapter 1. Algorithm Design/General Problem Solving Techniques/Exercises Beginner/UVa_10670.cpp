// UVa 10670
// Work Reduction
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAXL = 102;
const int INF = 1e9;

struct Answer {
    string name;
    int cost;
    bool operator<(Answer rhs) const{
        return this->cost < rhs.cost ||
            (this->cost == rhs.cost && this->name < rhs.name);
    }
};

int N, M, L;
string agency;
int A, B;

Answer ans[MAXL];

void read_agency() {
    agency = "";
    char ch;
    while (isupper(ch = getchar()))
        agency += ch;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &N, &M, &L);
        getchar();
        for (int i = 0; i < L; i++) {
            read_agency();
            scanf("%d,%d", &A, &B);
            getchar();

            int work = N, money = 0, min_val = INF;
            while (work >= M) {
                min_val = min(money + A * (work - M), min_val);
                work /= 2;
                money += B;
            }

            ans[i] = (Answer){agency, min_val};
        }

        sort(ans, ans + L);

        printf("Case %d\n", cas);
        for (int i = 0; i < L; i++)
            printf("%s %d\n", ans[i].name.c_str(), ans[i].cost);
    }

    return 0;
}
