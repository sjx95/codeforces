#include <cstdint>
#include <ios>
#include <iostream>
#include <cmath>
using namespace std;

const int64_t magic = 998244353;

void solve() {
	int l, r;
	cin >> l >> r;

	int size = 1;
	for (int x = r / l; (x=x/2) > 0; ++size);
	if (size == 1) {
		cout << 1 << ' ' << (r - l + 1) << endl;
		return;
	}


	int sp1 = r, sp2 = r;
	for (int i = 2, x = r; i < size; ++i) {
		sp1 = sp2 = x /= 2;
	}

	sp1 /= 3;
	sp2 /= 2;

	// cout << l << ' ' << sp1 << ' ' << sp2 << ' ' << r << endl;

	int64_t cnt = (sp2 - l + 1) % magic;
	for (int64_t p = (sp1 - l + 1), b = size - 1; p > 0; p /= 2) {
		if (p % 2) cnt = (cnt + b) % magic;
		b = b * 2 % magic;
	}
	cout << size << ' ' << cnt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) 
		solve();
}
