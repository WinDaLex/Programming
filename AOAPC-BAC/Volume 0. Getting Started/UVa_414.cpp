// UVa 414
// Machined Surfaces
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

int N;
char image[100000];

int main() {
    while (scanf("%d", &N) && N) {
        getchar();
        int min_val = 30, sum = 0;
        for (int i = 0; i < N; i++) {
            gets(image);
            int cnt = 0;
            for (int i = 0; i < strlen(image); i++)
                if (isspace(image[i])) cnt++;
            min_val = min(min_val, cnt);
            sum += cnt;
        }
        printf("%d\n", sum - N * min_val);
    }

    return 0;
}
