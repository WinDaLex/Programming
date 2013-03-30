// UVa 1344
// Tian Ji -- The Horse Racing
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

const int MAXN = 1002;

int N;
int speed;

int main() {
    while (scanf("%d", &N) && N) {
        deque<int> tian, king;
        for (int i = 0; i < N; i++) {
            scanf("%d", &speed);
            tian.push_back(speed);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &speed);
            king.push_back(speed);
        }

        sort(tian.begin(), tian.end());
        sort(king.begin(), king.end());
   
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (tian.back() > king.back()) {
                ans += 200;
                tian.pop_back();
                king.pop_back();
            } else if (tian.back() < king.back()) {
                ans -= 200;
                tian.pop_front();
                king.pop_back();
            } else {
                if (tian.front() > king.front()) {
                    ans += 200;
                    tian.pop_front();
                    king.pop_front();
                } else {
                    ans += tian.front() < king.back() ? -200 : 0;
                    tian.pop_front();
                    king.pop_back();
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
