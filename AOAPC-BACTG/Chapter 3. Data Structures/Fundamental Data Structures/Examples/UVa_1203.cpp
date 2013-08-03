// UVa 1203
// Argus
// by A Code Rabbit

#include <cstdio>
#include <queue>
using namespace std;

struct Item {
    int time, Q_num, Period;
    bool operator<(Item rhs) const {
        return time > rhs.time || (time == rhs.time && Q_num > rhs.Q_num);
    }
};

int K;
char S[10];

int main() {
    priority_queue<Item> pq;

    while (scanf("%s", S) == 1 && S[0] != '#') {
        Item item;
        scanf("%d%d", &item.Q_num, &item.Period);
        item.time = item.Period;
        pq.push(item);
    }
    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        Item top = pq.top();
        pq.pop();
        printf("%d\n", top.Q_num);

        top.time += top.Period;
        pq.push(top);
    }

    return 0;
}
