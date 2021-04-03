#include <stdio.h>
 
int mat[1000][1000];
char o[100000];
int ans[1000][1000];
 
void swap(int *a, int *b) {
	int x = *a;
	*a = *b;
	*b = x;
}
 
void solve(int n, int m) {
	int fo[6] = {0, 1, 2, 0, 0, 0};
	for (int i = 0; i < m; ++i) {
		switch (o[i]) {
			case 'D':
			case 'U':
				fo[3] += (o[i] == 'D') - (o[i] == 'U');
				break;
			case 'L':
			case 'R':
				fo[4] += (o[i] == 'R') - (o[i] == 'L');
				break;
			case 'I':
				swap(&fo[2], &fo[1]);
				swap(&fo[5], &fo[4]);
				break;
			case 'C':
				swap(&fo[2], &fo[0]);
				swap(&fo[5], &fo[3]);
				break;
		}
	}
	for (int i = 3; i < 6; ++i)
		fo[i] = (fo[i] + m / n * n + n) % n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int p[3] = {i, j, mat[i][j] - 1};
			int q[3] = {
				(p[fo[0]] + fo[3]) % n,
				(p[fo[1]] + fo[4]) % n,
				(p[fo[2]] + fo[5]) % n
			};
			ans[q[0]][q[1]] = q[2] + 1;
		}
}
 
int main() {
	int t;
	scanf("%d", &t);
 
	for (int i = 0; i < t; ++i) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) scanf("%d", &mat[i][j]);
		scanf("%s", o);
		solve(n, m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				printf("%d ", ans[i][j]);
			printf("\n");
		}
	}
 
	return 0;
}