// UVaOJ 123
// Searching Quickly
// by A Code Rabbit

#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

string word;
string title;

string ToLower(string str);
string ToUpper(string str);

int main() {
    set<string> words;
    while (getline(cin, word)) {
        if (word == "::") break;
        else words.insert(ToLower(word));
    }

    multimap<string, string> kwic;
    while (getline(cin, title)) {
        title = ToLower(title);
        string key;
        string val = title;
        for (int i = 0; i <= title.length(); i++) {
            if ((i == title.length() || title[i] == ' ') && key != "") {
                if (!words.count(key)) {
                    key = ToUpper(key);
                    for (int j = 0; j < key.length(); j++)
                        val[i - key.length() + j] = key[j];
                    kwic.insert(make_pair(key, val));
                    val = title;
                }
                key = "";
            } else {
                key += title[i];
            }
        }
    }

    for (map<string, string>::iterator iter = kwic.begin();
        iter != kwic.end();
        ++iter)
    {
        cout << iter->second << endl;
    }
    

    return 0;
}

string ToLower(string str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}

string ToUpper(string str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}
