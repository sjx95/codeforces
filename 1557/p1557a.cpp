#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int64_t n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; cin >> arr[i++]);

	sort(arr.begin(), arr.end());

	int64_t sum = 0;
	for (int i = 0; i < n - 1; ++i)
		sum += arr[i];

	double a = double(sum) / (n-1);
	double b = double(arr[n-1]);
	printf("%.8lf\n", a + b);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
