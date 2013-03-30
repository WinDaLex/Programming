// UVa 10815
// Andy's First Dictionary
// by A Code Rabbit

#include <cctype>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

char ch;

int main() {
    set<string> dictionary;
    string word;
    while (scanf("%c", &ch) != EOF) {
        if (!isalpha(ch)) {
            if (word != "") dictionary.insert(word);
            word = "";
        } else {
            word += tolower(ch);
        }
    }
    for (set<string>::iterator
        iter = dictionary.begin(); iter != dictionary.end(); ++iter)
    {
        puts(iter->c_str());
    }

    return 0;
}
