// UVa 1523
// Helicopter
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double INF = 1e20;
const double V[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const double H[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

double M[8];

bool read() {
	bool bo = false;
	for (int i = 0; i < 8; i++) {
		scanf("%lf", &M[i]);
		if (M[i] > 0) bo = true;
	}
	return bo;
}

double f(int turn[8]) {
	double x = 0, y = 0;
	for (int i = 0; i < 8; i++) {
		int j = turn[i];
		x += M[j] * V[i];
		y += M[j] * H[i];
	}
	return sqrt(x * x + y * y);
}

int main() {
	while (read()) {
		double ans = INF;
		int turn[8] = {0, 1, 2, 3, 4, 5, 6, 7};
		do {
			ans = min(ans, f(turn));
		} while (next_permutation(turn, turn + 8));
		printf("%.3lf\n", ans);
	}
	
	return 0;
}
