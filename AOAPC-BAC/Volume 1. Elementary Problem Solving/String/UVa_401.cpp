// UVa 401
// Palindromes
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>

const char CH_REV[] = {
    'A', ' ', ' ', ' ', '3', ' ', ' ',
    'H', 'I', 'L', ' ', 'J', 'M', ' ',
    'O', ' ', ' ', ' ', '2', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'
};

const char NUM_REV[] = {
    ' ', '1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' '
};

char str[100];

int main() {
    while (gets(str)) {
        bool palindrome = true;
        bool mirrored = true;
        for (int i = 0, j = strlen(str) - 1; i <= j; i++, j--) {
            if (str[i] != str[j])
                palindrome = false;
            if (isupper(str[i])) {
                if (CH_REV[str[i] - 'A'] != str[j])
                    mirrored = false;
            } else {
                if (NUM_REV[str[i] - '0'] != str[j])
                    mirrored = false;
            }
        }
        printf("%s -- ", str);
        if (palindrome && mirrored)
            puts("is a mirrored palindrome.");
        else if (palindrome && !mirrored)
            puts("is a regular palindrome.");
        else if (!palindrome && mirrored)
            puts("is a mirrored string.");
        else
            puts("is not a palindrome.");
        puts("");
    }

    return 0;
}

