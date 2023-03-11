#include <iostream>
#include <string>
using namespace std;

const string pattern = "FBFFBFFB";

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	for (auto i = 0; i < pattern.length(); ++i) {
		bool ok = true;
		for (auto j = 0; j < s.length(); ++j) {
			if (s[j] != pattern[(i + j) % pattern.length()]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	for (auto i = 0; i < t; ++i)
		solve();
}
