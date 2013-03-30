// UVaOJ 439
// Knight Moves
// by A Code Rabbit

#include <cstdio>
#include <cstring>

struct Status {
    int x;
    int y;
    int num_steps;
};

struct Change {
    int x;
    int y;
};

const Change CHANGE[] = {
              {-2, -1},        {-2, 1},
    {-1, -2},                           {-1, 2},

    { 1, -2},                           { 1, 2},    
              { 2, -1},        { 2, 1},
};

const int LIMITS = 10;
char a_col, a_row;
char b_col, b_row;

bool is_visited[LIMITS][LIMITS];
Status queue[LIMITS * LIMITS];
int target_x, target_y;
int head, tail;
int ans;
bool is_found;

void INIT();
void BFS();
void Search(int x, int y, int num_steps);

int main() {
    while (scanf("%c%c %c%c", &a_col, &a_row, &b_col, &b_row) != EOF) {
        getchar();
        // BFS.
        BFS();
        // Outputs.
        printf("To get from %c%c to %c%c takes %d knight moves.\n", a_col, a_row, b_col, b_row, ans);
    }

    return 0;
}

void INIT() {
    memset(is_visited, 0, sizeof(is_visited));
    head = 0;
    tail = 1;
    queue[0].x = a_row - '0';
    queue[0].y = a_col - 'a';
    queue[0].num_steps = 0;
    target_x = b_row - '0';
    target_y = b_col - 'a';
    is_found = false;
} 

void BFS() {
    // Judge special sentence.
    if (a_row == b_row
     && a_col == b_col) {
        ans = 0;
        return;
    }
    // INIT.
    INIT();
    // BFS.
    while (head < tail) {
        for (int i = 0; i < 8; i++) {
            Search(queue[head].x + CHANGE[i].x, queue[head].y + CHANGE[i].y, queue[head].num_steps + 1);
        }
        head++;
    }
}

void Search(int x, int y, int num_steps) {
    // Exit.
    if (is_found) {
        return;
    }
    if (x <= 0 || x > 8
     || y < 0 || y >= 8) {
        return;
    }
    if (is_visited[x][y]) {
        return;
    }
    // Judge whether is the target.
    if (x == target_x
     && y == target_y) {
        ans = num_steps;
        is_found = true;
        return;
    }
    // Continue.
    queue[tail].x = x;
    queue[tail].y = y;
    queue[tail].num_steps = num_steps;
    is_visited[x][y] = true;
    tail++;
}
