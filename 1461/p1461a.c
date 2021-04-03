#include<stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i=0; i < t; ++i) {
		int n, k;
		scanf("%d %d", &n, &k);
		int p = n - k;
		for (int j = p - 1; j >= 0; --j) {
			printf("%c", 'c'-(j%3));
		}
		
		printf("a");
		if (k==1) {
			printf("\n");
			continue;
		}
		for (int j = 0; j < k-2; ++j) {
			printf("b");
		}
		printf("a\n");

	}
}
