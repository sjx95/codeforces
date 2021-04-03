#include <cstdint>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, x;
		cin >> n >> x;
		int64_t sum = 0, max = 0;
		for (int j = 0; j < n; ++j) {
			int64_t a;
			cin >> a;
			sum += a;
			max += (a + x - 1) / x;
		}
		int64_t min = (sum + x - 1) / x;
		cout << min << ' ' << max << endl;
	}
	return 0;
}
