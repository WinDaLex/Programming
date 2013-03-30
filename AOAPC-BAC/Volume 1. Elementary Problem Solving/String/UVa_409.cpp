// UVa 409
// Excuses, Excuses!
// by A Code Rabbit

#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 22;

int K, E;
string str;

string excuse[MAXN];
set<string> keyword;

int count(string str) {
    int res = 0;
    string cur;
    for (int j = 0; j < str.length(); j++) {
        if (!isalpha(str[j])) {
            if (keyword.count(cur)) res++;
            cur = "";
        } else {
            cur += tolower(str[j]);
        }
    }
    return res;
}

int main() {
    int cas = 1;
    while (scanf("%d%d", &K, &E) != EOF) {
        getchar();
        keyword.clear();
        for (int i = 0; i < K; i++) {
            getline(cin, str);
            keyword.insert(str);
        }

        int max_val = 0;
        vector<string> ans;
        for (int i = 0; i < E; i++) {
            getline(cin, excuse[i]);
            int tmp  = count(excuse[i]);
            if (tmp > max_val) {
                max_val = tmp;
                ans.clear();
                ans.push_back(excuse[i]);
            } else
            if (tmp == max_val) {
                ans.push_back(excuse[i]);
            } 
        }

        printf("Excuse Set #%d\n", cas++);
        for (int i = 0; i < ans.size(); i++)
            puts(ans[i].c_str());
        puts("");
    }

    return 0;
}
