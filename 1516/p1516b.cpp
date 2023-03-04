#include <iostream>
#include <cstdint>
using namespace std;

void solve() {
	int n;
	cin >> n;

	uint64_t a[2000];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	uint64_t all = 0;
	for (int i = 0; i < n; ++i) {
		all ^= a[i];
	}

	if (all == 0) {
		cout << "YES" << endl;
		return;
	}

	uint64_t ls = 0, ms = 0, rs = 0;
	for (int i = 0; i < n; ++i) {
		if (ls != all) {
			ls ^= a[i];
			continue;
		}
		if (ms != all) {
			ms ^= a[i];
			continue;
		}
		if (rs != all) {
			rs ^= a[i];
			continue;
		}
	}

	if (ls == ms && ms == rs) {
		cout  << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}
