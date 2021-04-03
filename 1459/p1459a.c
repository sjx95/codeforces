#include <stdio.h>

void solve() {
	int n;
	scanf("%d\n", &n);
	
	char r[1000], b[1000];
	scanf("%s", r);
	scanf("%s", b);
	int diff = 0;
	for (int i = 0; i < n; ++i) {
		diff += r[i] > b[i];
		diff -= b[i] > r[i];
	}

	if (diff > 0) 
		printf("RED\n");
	else if (diff < 0)
		printf("BLUE\n");
	else 
		printf("EQUAL\n");
}		

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}
