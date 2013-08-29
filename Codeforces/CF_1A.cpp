// CF 1A
// Theatre Square
// by A Code Rabbit

#include <iostream>
using namespace std;

typedef long long LL;

LL N, M, A;

int main() {
    cin >> N >> M >> A;
    cout << ((N + A - 1) / A) * ((M + A - 1) / A) << endl;

    return 0;
}
