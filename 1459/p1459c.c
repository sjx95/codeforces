#include <stdint.h>
#include <stdio.h>

unsigned long long a[200000];

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	unsigned long long r;
	for (r = a % b; r != 0; r = a % b) {
		a = b;
		b = r;
	}
	return b;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%llu", &a[i]);
		if (i == 0)
			continue;
		if (a[i] < a[0]) {
			unsigned long long t = a[0];
			a[0] = a[i];
			a[i] = t;
		}
		if (a[i] == a[0]) {
			--i;
			--n;
		}
	}

	unsigned long long g = a[1] - a[0];
	for (int i = 2; i < n; ++i) {
		g = gcd(g, a[i] - a[0]);
	}

	for (int i = 0; i < m; ++i) {
		unsigned long long b;
		scanf("%llu", &b);
		if (n == 1) 
			printf("%llu ", a[0] + b);
		else 
			printf("%llu ", gcd(a[0] + b, g));
	}
}

