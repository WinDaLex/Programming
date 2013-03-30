// UVaOJ 400
// Unix ls
// by A Code Rabbit

#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

const int MAXN = 102;

int n;
string filenames[MAXN];
int max_len;

int main() {
    while (cin >> n) {
        // Input and solve.
        max_len = 0;
        for (int i = 0; i < n; i++) {
            cin >> filenames[i];
            max_len = max((int)filenames[i].length(), max_len);
        }
        sort(filenames, filenames + n);
        // Output.
        for (int i = 0; i < 60; i++)
            cout << '-';
        cout << endl;
        int len_row = max_len + 2;
        int num_col = 62 / len_row;
        int num_row = (n + num_col - 1) / num_col;
        for (int i = 0; i < num_row; i++) {
            for (int j = 0; j < num_col; j++)
                if (j * num_row + i < n)
                    cout << setw(len_row) << left << filenames[j * num_row + i];
            cout << endl;
        }
    }

    return 0;
}
