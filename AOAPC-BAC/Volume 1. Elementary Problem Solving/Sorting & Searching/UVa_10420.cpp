// UVa 10420
// List of Conquests
// by A Code Rabbit

#include <cstdio>
#include <map>
#include <string>
using namespace std;

typedef map<string, int>::iterator iter;
const int MAXN = 75;

int N;
char str[MAXN];

map<string, int> list;
char country[MAXN];

int main() {
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        gets(str);
        sscanf(str, "%s", country);

        string tmp(country);
        if (list.count(tmp)) list[tmp]++;
        else list[tmp] = 1;
    }

    for (iter i = list.begin(); i != list.end(); ++i)
        printf("%s %d\n", i->first.c_str(), i->second);

    return 0;
}
