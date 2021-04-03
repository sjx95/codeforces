#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> x;
	set<int> s;

	for (int i = 0; i < n; ++i) {
		int xi;
		cin >> xi;

		for (int j = 0; j < x.size(); ++j) {
			s.insert(xi - x[j]);
		}

		x.push_back(xi);
	}

	cout << s.size() << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
