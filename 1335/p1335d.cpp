#include <iostream>
#include <string>
using namespace std;

void solve() {
	string s[9];
	for (int i = 0; i < 9; cin >> s[i++]);
	for (int i = 0; i < 9; ++i) {
		int j = (i * 3 + i / 3) % 9;
		--s[i][j];
		s[i][j] += 9 * (s[i][j] == 48);
	}
	for (int i = 0; i < 9; cout << s[i++] << endl);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
