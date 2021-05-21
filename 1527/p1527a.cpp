#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;

void solve() {
	uint64_t n;
	cin >> n;

	int cnt = 0;
	for (int x = n; x >> cnt ; ++cnt);

	uint64_t ret = (1 << (cnt - 1)) - 1;
	cout << ret << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
