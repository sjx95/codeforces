#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n, 0);
	map<int, int> v2i;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		v2i.insert(make_pair(arr[i], i));
	}

	int cnt = 1;
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; ++i) {
		int prev = arr[i-1];
		int x = arr[i];
		cnt += v2i[x] != v2i[prev] + 1;
	}

	cout << (cnt <= k ? "Yes" : "No") << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
