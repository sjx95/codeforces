#include <iostream>
#include <ostream>
using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n == 2) {
		cout << -1 << endl;
		return;
	}

	int m[n * n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int p = n * j + (j + i) % n;
			m[p] = n * i + j + 1;
		}
	}

	for (int i = 0; i < n * n; ++i) {
		cout << m[i] << ((i + 1) % n ? " " : "\n") << flush;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
