#include <iostream>
using namespace std;

void solve() {
	int n, m;
	int sum_r = 0, max_r = 0;
	int sum_b = 0, max_b = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int r;
		cin >> r;
		sum_r += r;
		max_r = sum_r > max_r ? sum_r : max_r;
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int b;
		cin >> b;
		sum_b += b;
		max_b = sum_b > max_b ? sum_b : max_b;
	}

	cout << max_r + max_b << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}
