#include <iostream>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int c[3] = {0, 0, 0};
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++c[a];
	}

	int b = c[2] % 2 * 2;
	if (c[1] - b >= 0 && (c[1] - b) % 2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;;	
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
