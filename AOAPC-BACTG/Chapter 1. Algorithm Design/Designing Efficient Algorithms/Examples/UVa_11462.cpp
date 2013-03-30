// UVa 11462
// Age Sort
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMIT = 102;

int N;
int age;

int cnt[LIMIT];

int main() {
    while (scanf("%d", &N) && N) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < N; i++) {
            scanf("%d", &age);
            cnt[age]++;
        }

        bool fst = true;
        for (int i = 0; i < LIMIT; i++)
            while (cnt[i]--)
                printf("%s%d", fst ? fst = false, "" : " ", i); 
        puts("");
    }

    return 0;
};
