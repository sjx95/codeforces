#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
	int64_t n;
	cin >> n;

	int64_t b = n / 2 + n % 2;
	b = max(b, int64_t(3));

	cout << b * 5 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
