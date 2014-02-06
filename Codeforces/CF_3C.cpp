// CF 3C
// Tic-tac-toe
// by A Code Rabbit

#include <cstdio>

enum Verdict {
    FIRST,
    SECOND,
    ILLEGAL,
    FIRST_WON,
    SECOND_WON,
    DRAW
};

const char MAP[][30] = {
    "first",
    "second",
    "illegal",
    "the first player won",
    "the second player won",
    "draw"
};

const int NUM_LINE = 8;
const int LINE[NUM_LINE][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

char grid[9];

char get() {
    char ch = getchar();
    while (ch != '0' && ch != 'X' && ch != '.')
        ch = getchar();
    return ch;
}

char equal(int a, int b, int c) {
    if (grid[a] == grid[b] && grid[b] == grid[c])
        return grid[a];
    return '\0';
}

Verdict judge() {
    int cnt_cross = 0, cnt_nought = 0;
    for (int i = 0; i < 9; i++) {
        if (grid[i] == 'X') cnt_cross++;
        if (grid[i] == '0') cnt_nought++;
    }

    bool turn_first;
    if (cnt_cross - cnt_nought == 1) turn_first = false;
    else if (cnt_cross == cnt_nought) turn_first = true;
    else return ILLEGAL;

    char res = '\0';
    for (int i = 0; i < NUM_LINE; i++) {
        char ch = equal(LINE[i][0], LINE[i][1], LINE[i][2]);
        if (ch == '.' || ch == '\0') continue;
        if ((res == 'X' || res == '0') && res != ch) return ILLEGAL;
        res = ch;
    }

    if (cnt_cross + cnt_nought == 9 && res == '\0') return DRAW;
    else if (res == 'X') return turn_first ? ILLEGAL : FIRST_WON;
    else if (res == '0') return turn_first ? SECOND_WON : ILLEGAL;
    else return turn_first ? FIRST : SECOND;
}

int main() {
    for (int i = 0; i < 9; i++)
        grid[i] = get();

    puts(MAP[judge()]);

    return 0;
}
