// UVaOJ 673
// Parentheses Balance
// by A Code Rabbit

#include <iostream>
#include <stack>
#include <string>

using namespace std;

enum Parentheses {
    BRACKET,
    PARENTHESIS,
};

string str;
int n;

stack<Parentheses> parentheses;
bool isYes;

int main() {
    cin >> n;
    cin.get();
    while (n--) {
        // Clear stack.
        while (!parentheses.empty()) {
            parentheses.pop();
        }
        // Operating.
        getline(cin, str);
        isYes = true;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                parentheses.push(PARENTHESIS);
            } else
            if (str[i] == '[') {
                parentheses.push(BRACKET);
            } else
            if (str[i] == ')') {
                if (parentheses.empty() || parentheses.top() != PARENTHESIS) {
                    isYes = false;
                    break;
                } else {
                    parentheses.pop();
                }
            } else
            if (str[i] == ']') {
                if (parentheses.empty() || parentheses.top() != BRACKET) {
                    isYes = false;
                    break;
                } else {
                    parentheses.pop();
                }
            }
        }
        // Judge and Output the answer.
        if (!parentheses.empty()) {
            isYes = false;
        }
        if (isYes) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
        
    return 0;
}
