// UVaOJ 10420
// List of Conquests
// by A Code Rabbit

#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int MAXN = 75;

int n;
char str[MAXN];

map<string, int> list;
char country[MAXN];

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        gets(str);
        sscanf(str, "%s", country);
        string tmp(country);
        if (list.count(tmp)) list[tmp]++;
        else list[tmp] = 1;
    }
    for (map<string, int>::iterator iter = list.begin();
        iter != list.end();
        ++iter)
    {
        printf("%s %d\n", iter->first.c_str(), iter->second);
    }

    return 0;
}
