// UVa 11988
// Broken Keyboard (a.k.a Beiju Text)
// by A Code Rabbit

#include <cstdio>
#include <list>
using namespace std;

typedef list<char>::iterator iter;

const int MAXN = 100002;

char ch;

int main() {
    while ((ch = getchar()) != EOF) {
        list<char> l;

        iter pos = l.end();
        do {
            if (ch != '[' && ch != ']') l.insert(pos, ch);
            else pos = (ch == '[' ? l.begin() : l.end());
        } while ((ch = getchar()) != '\n');

        for (iter i = l.begin(); i != l.end(); i++)
            putchar(*i);
        putchar('\n');
    }

    return 0;
}
