#include <iostream>
using namespace std;

int arr[200000], s[200000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; cin >> arr[i++]);

	int max = 0;
	for (int i = n - 1; i >= 0; --i) {
		s[i] = arr[i];
		int next = i + arr[i];
		if (next < n)
			s[i] += s[next];
		if (s[i] > max)
			max = s[i];
	}
	cout << max << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
