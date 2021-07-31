#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
	int m;
	cin >> m;

	int a[m], b[m];
	for (int i = 0; i < m; cin >> a[i++]);
	for (int i = 0; i < m; cin >> b[i++]);

	int64_t sa = 0, sb = 0;
	int i = 0, j = m - 1;
	while (i < j) {
		if (sb + b[i] <= sa + a[j])
			sb += b[i++];
		else
			sa += a[j--];
	}

	cout << max(sa, sb) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
