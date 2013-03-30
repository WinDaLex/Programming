// UVaOJ 11205
// The broken pedometer
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS_P = 17;
const int LIMITS_N = 102;

const int DIGIT[] = {
    1 <<  0, 1 <<  1, 1 <<  2, 1 <<  3,
    1 <<  4, 1 <<  5, 1 <<  6, 1 <<  7,
    1 <<  8, 1 <<  9, 1 << 10, 1 << 11,
    1 << 12, 1 << 13, 1 << 14, 1 << 15,
};

int t;
int n;
int p;

int symbol[LIMITS_N];

struct LED {
    int codification;
    int num;
};

LED queue[1 << LIMITS_P];
int head, tail;
bool visit[1 << LIMITS_P];
bool is_found;

bool CanIdentify(int codification);

void BFS();
void Init();
void Search(int codification, int num);

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &p);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            symbol[i] = 0;
            for (int j = 0; j < p; ++j) {
                int digit;
                scanf("%d", &digit);
                symbol[i] += DIGIT[p - j - 1] * digit;
            }
        }
        BFS();
    }

    return 0;
}

bool CanIdentify(int codification) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((symbol[i] & codification) ==
                (symbol[j] & codification))
            {
                return false;    
            }
        }
    }
    return true;
}

void BFS() {
    Init();
    Search(0, 0);
    while (head < tail) {
        int codification_now = queue[head].codification;
        int num_now = queue[head].num;
        for (int i = 0; i < p; ++i) {
            Search(codification_now | DIGIT[i], num_now + 1);
        }
        ++head;
    }
}

void Init() {
    memset(visit, false, sizeof(visit));
    head = 0;
    tail = 0;
    is_found = false;
}

void Search(int codification, int num) {
    // Exit.
    if (is_found) {
        return ;
    }
    if (visit[codification]) {
        return;
    }
    // Judge.
    if (CanIdentify(codification)) {
        printf("%d\n", num);
        is_found = true;
        return;
    }
    // Continue.
    queue[tail].codification = codification;
    queue[tail].num = num;
    ++tail;
    visit[codification] = true;
}
