#include <cstdint>
#include <iostream>
using namespace std;

int n;
int32_t a[300000];

bool hit(int p) {
	if (p <= 0 || p >= n)
		return false;
	else 
		return (a[p] > a[p-1] && a[p] > a[p+1]) || (a[p] < a[p-1] && a[p] < a[p+1]);
}

int solve() {
	cin >> n;
	for (int i = 0; i < n; cin >> a[i++]);

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += hit(i);
	}

	int min = cnt;
	for (int i = 0; i < n; ++i) {
		int oc = cnt - hit(i-1) - hit(i) - hit(i+1);
		int b = a[i];
		
		if (i != 0) {
			a[i] = a[i - 1];
			int nc = oc + hit(i-1) + hit(i) + hit(i+1);
			min = (nc < min) ? nc : min;
		}

		if (i != n - 1) {
			a[i] = a[i + 1];
			int nc = oc + hit(i-1) + hit(i) + hit(i+1);
			min = (nc < min) ? nc : min;
		}

		a[i] = 0;
		int nc = oc + hit(i-1) + hit(i) + hit(i+1);
		min = (nc < min) ? nc : min;

		a[i] = INT32_MAX;
		nc = oc + hit(i-1) + hit(i) + hit(i+1);
		min = (nc < min) ? nc : min;

		a[i] = b;
	}

	return min;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		cout << solve() << endl;
	return 0;
}
