// Codeforces #286 A
// Mr. Kitayuta's Gift

#include <iostream>
#include <string>
using namespace std;

string s;

bool is_palindrome(string &s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}

int main() {
    cin >> s;

    bool bo = false;
    for (int i = 0; i <= s.length(); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (bo) break;
            string t = s;
            t.insert(i, 1, c);
            if (is_palindrome(t)) {
                cout << t << endl;
                bo = true;
            }
        }
    }

    if (!bo) cout << "NA" << endl;

    return 0;
}
