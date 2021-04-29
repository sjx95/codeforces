#include <iostream>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	if (k == n * m - 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
