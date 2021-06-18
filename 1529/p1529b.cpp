#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int64_t> arr;
	for (int i = 0; i < n; ++i) {
		int64_t x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	if (n == 1 || *arr.rbegin() <= 0) {
		cout << n << endl;
		return;
	}

	if (*arr.begin() > 0) {
		cout << 1 << endl;
		return;
	}

	int64_t p = n - 1;
	int64_t max = INT64_MAX;
	for (int i = 1; i < n; ++i) {
		if (arr[i] > 0) {
			p = i;
			break;
		}
		int64_t d = arr[i] - arr[i-1];
		max = max < d ? max : d;
	}

	if (arr[p] <= max)
		++p;
	cout << p << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
