#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;

const vector<string> targets = {"abc", "acb", "bac", "bca", "cab", "cba"};

int main() {
	int n, m;
	cin >> n >> m;

	string str;
	cin >> str;

	vector<int64_t> bz[6];
	for (int i = 0; i < 6; ++i) {
		bz[i].push_back(0);
		for (int j = 0; j < n; ++j) {
			bz[i].push_back(*bz[i].rbegin() + (str[j] != targets[i][j%3]));
		}
	}

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;

		int64_t ret = n;
		for (int i = 0; i < 6; ++i) {
			ret = min(ret, bz[i][r] - bz[i][l-1]);
		}

		cout << ret << endl;
	}

	return 0;
}
