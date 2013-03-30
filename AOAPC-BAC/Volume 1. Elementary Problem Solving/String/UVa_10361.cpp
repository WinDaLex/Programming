// UVa 10361
// Automatic Poetry
// by A Code Rabbit

#include <cstdio>
#include <iostream>
using namespace std;

string s1, s2, s3, s4, s5;
string s;

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    while (T--) {
        getline(cin, s1, '<');
        getline(cin, s2, '>');
        getline(cin, s3, '<');
        getline(cin, s4, '>');
        getline(cin, s5);
        getline(cin, s);

        cout << s1 << s2 << s3 << s4 << s5 << endl;
        s.erase(s.end() - 3, s.end());
        cout << s << s4 << s3 << s2 << s5 << endl;
    }

    return 0;
}
