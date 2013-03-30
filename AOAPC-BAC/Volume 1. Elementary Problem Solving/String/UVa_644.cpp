// UVa 644
// Immediate Decodability
// by A Code Rabbit

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100000;

string str[MAXN];
int top;

bool is_prefix(string , string);

int main() {
    int cas = 1;
    top = 0;
    while (cin >> str[top]) {
        if (str[top] == "9") {
            bool bo = false;
            for (int i = 0; i < top; i++)
                for (int j = 0; j < top; j++)
                    if (i != j && is_prefix(str[i], str[j]))
                        bo = true;
            printf("Set %d is %simmediately decodable\n", cas++, bo ? "not " : "");
            top = 0;
        } else {
            top++;
        }
    }

    return 0;
}

bool is_prefix(string a, string b) {
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) return false;
    return true;
}
