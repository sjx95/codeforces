#include<stdio.h>
#include<limits.h>

void solve() {
	int w, h;
	scanf("%d %d", &h, &w);
	int map[500][500] = {0};
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char ch = getchar();
			switch (ch) {
				case '*':
					map[i][j] = 1;
					break;
				case '.':
					map[i][j] = 0;
					break;
				default:
					--j;
			}
		}
	}

	int ms[500][500] = {0};
	for (int i = h - 1; i >= 0; --i) {
		for (int j = 0; j < w; ++j) {
			if (!map[i][j]) { continue; }
			ms[i][j] = 1;
			if (i == h-1 || j == 0 || j == w-1) { continue; }
			int min = INT_MAX;
			if (ms[i+1][j-1] < min) {
				min = ms[i+1][j-1];
			}
			if (ms[i+1][j] < min) {
				min = ms[i+1][j];
			}
			if (ms[i+1][j+1] < min) {
				min = ms[i+1][j+1];
			}
			ms[i][j] += min;
		}
	}

	int cnt = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; cnt += ms[i][j++]);
	printf("%d\n", cnt);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i=0; i < t; ++i) {
		solve();
	}
}
