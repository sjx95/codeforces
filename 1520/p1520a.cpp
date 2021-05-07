#include <iostream>
#include <bitset>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	char last = 0;
	bitset<128> flags;

	for (char c : str) {
		if (c == last)
			continue;
		if (flags[c]) {
			cout << "NO" << endl;
			return;
		}
		flags[c] = true;
		last = c;
	}
	cout << "YES" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
