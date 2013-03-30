// UVaOJ 10167
// Birthday Cake
// by A Code Rabbit

#include <cstdio>

const int LIMITS = 10000;
const int RANGE = 500;

int n;

struct Point {
    int x, y;
};

Point cherry[LIMITS];

void Enumerate();
bool IsFair(int a, int b);

int main() {
    while (scanf("%d", &n), n) {
        // Inputs.
        for (int i = 0; i < n * 2; ++i) {
            scanf("%d%d", &cherry[i].x, &cherry[i].y);
        }
        // Brute force! And then, outputs.
        Enumerate();
    }

    return 0;
}

void Enumerate() {
    for (int i = -RANGE; i < RANGE; ++i) {
        for (int j = -RANGE; j < RANGE; ++j) {
            if (IsFair(i, j)) {
                printf("%d %d\n", i, j);
                return;
            }
        }
    }
}

bool IsFair(int a, int b) {
    int difference = 0;
    bool cut_cherry = false;
    for (int i = 0; i < n * 2; ++i) {
        if (a * cherry[i].x + b * cherry[i].y > 0) {
            ++difference;
        } else
        if (a * cherry[i].x + b * cherry[i].y < 0) {
            --difference;
        } else {
            // If you cut a cherry into half, two children wouldn't be happy.
            return false;
        }
    }
    if (difference) {
        return false;
    } else {
        return true;
    }
}
