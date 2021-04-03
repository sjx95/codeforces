#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int x[100000];

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; cin >> x[i++]);
	sort(x, x + n);

	int cnt = 0, last = 0;
	for (int i = 0; i < n; ++i) {
		if (x[i] > last) {
			++cnt;
			last = x[i];
			continue;
		}
		if (x[i] == last) {
			++cnt;
			last = ++x[i];
			continue;
		}
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
