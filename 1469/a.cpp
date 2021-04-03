#include <iostream>
#include <string>
using namespace std;

string solve() {
	string s;
	cin >> s;
	int n = s.length(), fl, fr;
	for (int i = 0; i < n; ++i) {
		switch (s[i]) {
			case '(':
				fl = i;
				break;
			case ')':
				fr = i;
				break;
		}
	}
	int l, m, r;
	if (fl < fr) {
		l = fl;
		m = fr - fl - 1;
		r = n - fr - 1;
	} else {
		l = fr - 1;
		m = fl - fr - 1;
		r = n - fl - 2;
	}

	if (l < 0 || r < 0)
		return "NO";
	if ((l + m + r) % 2 != 0)
		return "NO";
	return "YES";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		cout << solve() << endl;
	return 0;
}
