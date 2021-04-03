#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int s[200000] = {0};

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	int tw = (a < b ? a : n - a + 1);
	int mt = abs(a - b) - 1;

	for (int i = 0; i < m; ++i) {
		cin >> s[i];
	}

	sort(s, s + m);

	int cnt = 0;
	for (int i = 0; (i < mt) && (cnt < m); ++i) {
		if (s[cnt] <= tw + i)
			++cnt;
	}
	cout << cnt << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
