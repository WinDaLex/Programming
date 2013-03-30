// UVaOJ 120
// Stacks of Flapjacks
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 32;

int stack[MAXN];
int top;
char ch;

void Tranform(int idx);
void Flip(int num);

int main() {
    while (scanf("%d%c", &stack[0], &ch) != EOF) {
        top = 1;
        while (ch != '\n')
            scanf("%d%c", &stack[top++], &ch);
        for (int i = 0; i < top; i++)
            printf("%d%c", stack[i], i < top - 1 ? ' ' : '\n');
        Tranform(1);
        puts("0");
    }

    return 0;
}

void Tranform(int x) {
    if (x > top) return;
    int idx = max_element(stack, stack + top - x + 1) - stack;
    int pos = top - idx;
    if (pos != x) {
        if (pos != top) {
            printf("%d ", pos);
            Flip(pos);
        } else {
            printf("%d ", x);
            Flip(x);
        }
        Tranform(x);
    } else {
        Tranform(x + 1);
    }
}

void Flip(int x) {
    int num = top - x;
    for (int i = 0; i < (num + 1) / 2; i++)
        swap(stack[i], stack[num - i]);
}
