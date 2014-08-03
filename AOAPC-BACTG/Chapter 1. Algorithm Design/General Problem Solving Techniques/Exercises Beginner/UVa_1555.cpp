// UVa 1555
// Garland
// by A Code Rabbit

#include <cstdio>

const double EPS = 1e-12;

int N;
double A;

bool check(double h2, double &hn) {
	double h1 = A;
	for (int i = 3; i <= N; i++) {
		hn = h2 * 2 - h1 + 2;
		h1 = h2;
		h2 = hn;
		if (hn < 0) return false;
	}
	return true;
}

int main() {
	while (scanf("%d%lf", &N, &A) != EOF) {
		double l = 0, r = A, m, ans;
		while (r - l > EPS) {
			m = (l + r) / 2;
			if (check(m, ans)) r = m;
			else l = m;
		}

		check(r, ans);
		printf("%.2lf\n", ans);
	}

	return 0;
}
