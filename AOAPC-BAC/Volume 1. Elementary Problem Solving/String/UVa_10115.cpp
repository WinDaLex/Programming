// UVa 10115
// Automatic Editing
// by A Code Rabbit

#include <iostream>
using namespace std;

const int MAXN = 100000;

int N;
string rules[MAXN][2];
string str;

int main() {
    while (cin >> N && N) {
        cin.get();
        for (int i = 0; i < N; i++) {
            getline(cin, rules[i][0]);
            getline(cin, rules[i][1]);
        }
        getline(cin, str);
        for (int i = 0; i < N; i++) {
            int idx;
            while ((idx = str.find(rules[i][0])) != string::npos)
                str.replace(idx, rules[i][0].length(), rules[i][1]);
        }
        cout << str << endl;
    }

    return 0;
}
