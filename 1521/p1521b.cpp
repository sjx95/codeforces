#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void solve() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; cin >> arr[i++]);

	vector<int> op;
	for (int i = 0; i < n-1; ++i) {
		if (gcd(arr[i], arr[i+1]) == 1)
			continue;

		while (gcd(arr[i], arr[i+1]) != 1 || (i != 0 && gcd(arr[i-1], arr[i]) != 1)) {
			int *p = arr[i] <= arr[i+1] ? &arr[i+1] : &arr[i];
			*p = (*p % 2000000000 + rand()) + 1;
		}
		op.push_back(i+1);
		op.push_back(i+2);
		op.push_back(arr[i]);
		op.push_back(arr[i+1]);
	}

	cout << op.size() / 4 << endl;
	for (int i = 0; i < op.size(); ++i) {
		cout << op[i] << ((i+1)%4 ? " " : "\n");
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
