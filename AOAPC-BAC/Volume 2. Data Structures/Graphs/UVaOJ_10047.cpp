// UVaOJ 10047
// The Monocycle
// by A Code Rabbit

#include <cstdio> 
#include <cstring>

const int LIMITS = 50;
const int LIMITS_QUEUE = 5000000;

struct Change {
    int x;
    int y;
};

const Change CHANGE[] = {
    {-1,  0}, // NORTH
    { 1,  0}, // SOUTH
    { 0, -1}, // WEST
    { 0,  1}, // EAST
};

enum Color {
    GREEN = 0,
    BLACK = 1,
    RED = 2,
    BLUE = 3,
    WHITE = 4,
};

enum Direction {
    NORTH = 0,
    SOUTH = 1,
    WEST = 2,
    EAST = 3,
};

int num_case = 0;

char grid[LIMITS][LIMITS];
int m, n;

struct Status {
    int x;
    int y;
    Direction direction;
    Color color;
    int t;
};

Status queue[LIMITS_QUEUE];
int t_visit[LIMITS][LIMITS][10][10];
int head, tail;
int ans;
bool is_found;

void BFS();
void INIT();
void Search(int x, int y, Direction direction, Color color, int t);

int main() {
    while (scanf("%d%d", &m, &n), m || n) {
        getchar();
        // Inputs.
        for (int i = 0; i < m; ++i) {
            gets(grid[i]);
        }
        // BFS.
        BFS();
        // Outputs.
        if (++num_case > 1) {
            printf("\n");
        }
        printf("Case #%d\n", num_case);
        if (is_found) {
            printf("minimum time = %d sec\n", ans);
        } else {
            printf("destination not reachable\n");
        }
    }

    return 0;
}

void BFS() {
    // INIT.
    INIT();
    // Insert head of the queue.
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'S') {
                Search(i, j, NORTH, GREEN, 0);
                break;
            }
        }
    }
    // BFS.
    while (head < tail) {
        Status now = queue[head];
        // Judge whether this is target.
        if (grid[now.x][now.y] == 'T' && now.color == GREEN) {
            ans = now.t;
            is_found = true;
            break;
        }
        // Search.
        for (int i = 0; i < 4; ++i) {
            // Compete the times of turning.
            int times_turn;
            if (now.direction == i) {
                times_turn = 1;
            } else
            if (now.direction + i != 1
             && now.direction + i != 5) {
                times_turn = 2;
            } else {
                times_turn = 3;
            }
            // Search.
            Search(now.x + CHANGE[i].x, now.y + CHANGE[i].y,
                   (Direction)i, (Color)((now.color + 1) % 5), now.t + times_turn);
        }
        // Next.
        ++head;
    }
}

void INIT() {
    memset(t_visit, 0, sizeof(t_visit));
    head = 0;
    tail = 0;
    is_found = false;
}

void Search(int x, int y, Direction direction, Color color, int t) {
    // Exit.
    if (x < 0 || x >= m
     || y < 0 || y >= n) {
        return;
    }
    if (grid[x][y] == '#') {
        return;
    }
    if (t_visit[x][y][direction][color] 
     && t >= t_visit[x][y][direction][color] ) {
        return;
    }
    // Flag.
    t_visit[x][y][direction][color] = t;
    // Push.
    int pos_insert = tail++;
    while (t < queue[pos_insert - 1].t) {
        queue[pos_insert] = queue[pos_insert - 1];
        --pos_insert;
    }
    queue[pos_insert].x = x;
    queue[pos_insert].y = y;
    queue[pos_insert].direction = direction;
    queue[pos_insert].color = color;
    queue[pos_insert].t = t;
}
