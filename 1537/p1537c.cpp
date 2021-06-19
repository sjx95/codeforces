#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int pos = 1;
	for (int i = pos; i < n; ++i) {
		if (arr[i] - arr[i-1] < arr[pos] - arr[pos-1])
			pos = i;
	}

	pos = (n <= 2 ? n : pos);
	for (int i = pos; i < n; ++i)
		cout << arr[i] << ' ';
	for (int i = 0; i < pos; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
		solve();
	return 0;
}
