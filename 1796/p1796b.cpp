#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void solve() {
	string a, b;
	cin >> a >> b;

	if (*a.begin() == *b.begin()) {
		cout << "YES" << endl << *a.begin() << '*' << endl;
		return;
	} else if (*a.rbegin() == *b.rbegin()) {
		cout << "YES" << endl << '*' << *a.rbegin() << endl;
		return;
	}

	bitset<27*27> bs;
	for (auto iter = a.begin(); iter + 1 < a.end(); ++iter) {
		int pos = (*iter - 'a') * 26 + (*(iter+1) - 'a');
		bs.set(pos, true);
	}

	for (auto iter = b.begin(); iter + 1 < b.end(); ++iter) {
		int pos = (*iter - 'a') * 26 + (*(iter+1) - 'a');
		if (bs.test(pos)) {
			cout << "YES" << endl << '*' << *iter << *(iter+1) << '*' << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) 
		solve();
}
