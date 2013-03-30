// UVaOJ 156
// Ananagrams
// by A Code Rabbit

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

string str;

int main() {
    map<string, string> words;
    multiset<string> anagrams;
    while (cin >> str && str != "#") {
        string tmp(str);
        for (int i = 0; i < tmp.length(); i++)
            tmp[i] = tolower(tmp[i]);
        sort(tmp.begin(), tmp.end());
        words.insert(make_pair(str, tmp));
        anagrams.insert(tmp);
    }

    for (map<string, string>::iterator iter = words.begin();
        iter != words.end();
        ++iter)
    {
        if (anagrams.count(iter->second) == 1)
            cout << iter->first << endl;
    }

    return 0;
}
