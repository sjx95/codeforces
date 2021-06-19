#include <iostream>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cnt += a - 1;
	}

	cout << (cnt >= 0 ? cnt : 1) << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		solve();
	return 0;
}
