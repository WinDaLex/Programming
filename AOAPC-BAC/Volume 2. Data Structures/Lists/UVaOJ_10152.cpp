// UVaOJ 10152
// ShellSort
// by A Code Rabbit

#include <iostream>
#include <map>
#include <stack>

using namespace std;

int k;

string original_ordering[200];
string desired_ordering[200];
int n;

map<string, int> turtles;
stack<string> operations;

int main() {
    cin >> k;
    while (k--) {
        // Inputs.
        cin >> n;
        cin.get();
        for (int i = 0; i < n; ++i) {
            getline(cin, original_ordering[i]);
            turtles[original_ordering[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            getline(cin, desired_ordering[i]);
        }
        // Run.
        for (int i = 0; i < n; ++i) {
            bool isSorted = true;
            for (int j = i; j < n - 1; j++)
                if (turtles[desired_ordering[j]]
                  > turtles[desired_ordering[j + 1]]) {
                    isSorted = false;
                    break;
                }
            if (isSorted) {
                break;
            } else {
                operations.push(desired_ordering[i]);
            }
        }
        // Outputs.
        while (!operations.empty()) {
            cout << operations.top() << endl;
            operations.pop();
        }
        cout << endl;
    }

    return 0;
}
