#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[200000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; cin >> arr[i++]);
	sort(arr, arr + n);

	int sa = 0, sb = 0;
	for (int i = 0; i < n; ++i) {
		int a = arr[n - i - 1];
		if (i % 2 == 0 && a % 2 == 0)
			sa += a;
		if (i % 2 && a % 2)
			sb += a;
	}
	
	string ret = "Tie";
	if (sa > sb)
		ret = "Alice";
	if (sb > sa)
		ret = "Bob";
	cout << ret << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
