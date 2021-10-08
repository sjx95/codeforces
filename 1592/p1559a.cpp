#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int64_t n, h;
	cin >> n >> h;
	vector<int64_t> weapons(n);

	for (int i = 0; i < n; cin >> weapons[i++]);
	sort(weapons.rbegin(), weapons.rend());
	
	int64_t a = weapons[0], b = weapons[1];
	int64_t cnt = h / (a + b) * 2 + (h % (a + b) > a) + (h % (a + b) > 0);
	cout << cnt << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
