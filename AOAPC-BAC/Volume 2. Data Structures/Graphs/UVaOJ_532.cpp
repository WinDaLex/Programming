// UVaOJ 532
// Dungeon Master
// by A Code Rabbit

#include <cstdio>
#include <cstring>

struct Status {
    int x;
    int y;
    int z;
    int t;
};

struct Change {
    int x;
    int y;
    int z;
};

const Change CHANGE[] = {
    {-1,  0,  0},
    { 1,  0,  0},
    { 0, -1,  0},
    { 0,  1,  0},
    { 0,  0, -1},
    { 0,  0,  1},
};

const int LIMITS = 50;

int l, r, c;

char dungeons[LIMITS][LIMITS][LIMITS];

int original_x, original_y, original_z;
int ans;

Status queue[LIMITS * LIMITS * LIMITS];
int head, tail;
bool is_found;

void INIT();
void BFS();
void Search(int x, int y, int z, int t);

int main() {
    while (scanf("%d%d%d", &l, &r, &c)) {
        getchar();
        // Exit.
        if (!l && !r && !c) {
            break;
        }
        // Intputs.
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j <= r; ++j) {
                gets(dungeons[i][j]);
            }
        }
        // Search original position and target.
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    if (dungeons[i][j][k] == 'S') {
                        original_x = i;
                        original_y = j;
                        original_z = k;
                    }
                }
            }
        }
        // BFS.
        BFS();
        // Outputs.
        if (is_found) {
            printf("Escaped in %d minute(s).\n", ans);
        } else {
            printf("Trapped!\n");
        }
    }
    
    return 0;
}

void INIT() {
    head = 0;
    tail = 0;
    is_found = false;   
}

void BFS() {
    INIT();
    Search(original_x, original_y, original_z, 0);
    while (head < tail) {
        for (int i = 0; i < 6; ++i) {
            Search(queue[head].x + CHANGE[i].x,
                   queue[head].y + CHANGE[i].y,
                   queue[head].z + CHANGE[i].z,
                   queue[head].t + 1);   
        }
        ++head;
    }
}
    
void Search(int x, int y, int z, int t) {
    // Exit.
    if (is_found) {
        return;
    }
    if (x < 0 || x >= l
     || y < 0 || y >= r
     || z < 0 || z >= c) {
        return;
    }
    if (dungeons[x][y][z] == '#') {
        return;
    }
    // Judge whether is target.
    if (dungeons[x][y][z] == 'E') {
        ans = t;
        is_found = true;
        return;
    }
    // Continue.
    queue[tail].x = x;
    queue[tail].y = y;
    queue[tail].z = z;
    queue[tail].t = t;
    dungeons[x][y][z] = '#';
    tail++;
}
