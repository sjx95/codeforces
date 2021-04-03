#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector< pair<int, int> > seq;
	while (n > 2) {
		int h = ceil(sqrt(n));
		for (int i = n - 1; i > h; --i)
			seq.push_back(make_pair(i, n));
		seq.push_back(make_pair(n, h));
		seq.push_back(make_pair(n, h));
		n = h;
	}

	cout << seq.size() << endl;
	for (int i = 0; i < seq.size(); ++i) {
		cout << seq[i].first << ' ' << seq[i].second << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
