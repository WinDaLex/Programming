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

bool visit[LIMITS_P];

int CountLedNum(int codification);
bool CanIdentify(int codification);

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
        memset(visit, false, sizeof(visit));
        int min = p + 1;
        for (int i = 0; i < 1 << p; ++i) {
            int num_led = CountLedNum(i);
            if (num_led < min && !visit[num_led]) {
                if (CanIdentify(i)) {
                    min = num_led;
                    visit[num_led] = true;
                }
            }
        }
        printf("%d\n", min);
    }

    return 0;
}

int CountLedNum(int codification) {
    int num_result = 0;
    for (int i = 0; i < p; ++i) {
        if (codification & DIGIT[i]) {
            ++num_result;
        }
    }
    return num_result;
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
