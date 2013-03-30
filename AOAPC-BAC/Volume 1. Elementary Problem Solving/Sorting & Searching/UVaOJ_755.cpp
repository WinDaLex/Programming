// UVaOJ 755
// 487--3279
// by A Code Rabbit

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const char MAP[] = "22233344455566677778889999";

int n;
string tel;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // Input.
        cin >> n;
        cin.get();
        map<string, int> cnt;  
        for (int i = 0; i < n; i++) {
            getline(cin, tel);
            tel.erase(remove(tel.begin(), tel.end(), '-'), tel.end());
            for (int i = 0; i < tel.length(); i++)
                if (isupper(tel[i]))
                    tel[i] = MAP[tel[i] - 'A'];
            tel.insert(3, "-");
            cnt[tel]++;
        }
        // Output.
        bool bo = false;
        for (map<string, int>::iterator
            iter = cnt.begin(); iter != cnt.end(); ++iter)
        {
            if (iter->second > 1) {
                cout << iter->first + " " << iter->second << endl;
                bo = true;
            }
        }
        if (!bo) cout << "No duplicates." << endl;
        if (t) cout << endl;
    }

    return 0;
}
