#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> arr(0, n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	auto old = arr;
	sort(arr.begin(), arr.end());

	if (old[0] == n && old [n-1] == 1) {
		cout << 3 << endl;
		return;
	}

	int ret = (*old.begin() != *arr.begin()) + (*old.rbegin() != *arr.rbegin());
	if (ret) {
		cout << ret << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] != old[i]) {
			ret = 1;
		}
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
