#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

void solve() {
	string sn;
	cin >> sn;

	int ret = 9 * (sn.length() - 1) + (sn[0] - 48);

	for (int i = 1; i < sn.length(); ++i) {
		if (sn[i] < sn[0]) 
			--ret;
		if (sn[i] == sn[0]) continue;
		else break;
	}

	cout << ret << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) 
		solve();
	return 0;
}
