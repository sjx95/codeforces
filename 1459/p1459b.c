#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int cnt = (n % 4 == 0);
	for (int i = 0; i < 2 * n; ++i) {
		int base = i * 2 - (i % 2 != 0);
		for (int j = 0; j < 2 * n; ++j) {
			if (i == 0 && j == 0)
				continue;
			
			int step = base + 2 * j;
			if (step > n)
				break;
			if ((n - step) % (2 * (2 - i % 2)) != 0)
				continue;
			
			cnt += 4 * (1 + (j != 0 && i != 0));
		}
	}

	printf("%d\n", cnt);
}

