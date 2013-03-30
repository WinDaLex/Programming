// UVa 1352
// Colored Cubes
// by A Code Rabbit

#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MAXN = 6;
const int DICE24[24][6] = {
	{3, 1, 0, 5, 4, 2}, {3, 5, 1, 4, 0, 2}, {3, 4, 5, 0, 1, 2}, 
	{3, 0, 4, 1, 5, 2}, {4, 3, 0, 5, 2, 1}, {0, 3, 1, 4, 2, 5}, 
	{1, 3, 5, 0, 2, 4}, {5, 3, 4, 1, 2, 0}, {0, 1, 2, 3, 4, 5}, 
	{1, 5, 2, 3, 0, 4}, {5, 4, 2, 3, 1, 0}, {4, 0, 2, 3, 5, 1}, 
	{5, 1, 3, 2, 4, 0}, {4, 5, 3, 2, 0, 1}, {0, 4, 3, 2, 1, 5}, 
	{1, 0, 3, 2, 5, 4}, {1, 2, 0, 5, 3, 4}, {5, 2, 1, 4, 3, 0}, 
	{4, 2, 5, 0, 3, 1}, {0, 2, 4, 1, 3, 5}, {2, 4, 0, 5, 1, 3}, 
	{2, 0, 1, 4, 5, 3}, {2, 1, 5, 0, 4, 3}, {2, 5, 4, 1, 0, 3},
};

int N;
string cube[MAXN][6];

int rot[MAXN];
int ans;

string color[MAXN][6];

int compute() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 6; j++)
            color[i][DICE24[rot[i]][j]] = cube[i][j];

    int res = 0;
    for (int i = 0; i < 6; i++) {
        map<string, int> cnt;
        for (int j = 0; j < N; j++) {
            string cur = color[j][i];
            if (cnt.count(cur)) cnt[cur]++;
            else cnt[cur] = 1;
        }
        int max_val = 0;
        for (int j = 0; j < N; j++)
            max_val = max(cnt[color[j][i]], max_val);
        res += N - max_val;
    }
    return res;
}

void search(int x) {
    if (x == N) {
        ans = min(compute(), ans);
        return;
    }
    for (int i = 0; i < 24; i++) {
        rot[x] = i;
        search(x + 1);
    }
    return;
}

int main() {
    while (cin >> N && N) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 6; j++)
                cin >> cube[i][j];
 
        ans = N * 6;
        rot[0] = 0;
        search(1);

        cout << ans << endl;
    }

    return 0;
}
