#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int64_t sum = 0;
	vector<int64_t> a, b;
	
	for (int i = 0; i < n; ++i) {
		int ai;
		cin >> ai;
		a.push_back(ai);
	}

	for (int i = 0; i < n; ++i) {
		int bi;
		cin >> bi;
		b.push_back(bi);
		sum += a[i] * b[i];
	}

	int64_t max = sum;
	for (int i = 0; i < n; ++i) {
		int64_t sodd = sum, seven = sum;
		for (int j = 2; j <= n; ++j) {
			int l = i - (j - 1) / 2;
			if (l < 0) break;

			int r = i + j / 2;
			if (r >= n) break;

			int64_t diff = a[l] * b[r] + a[r] * b[l] - a[l] * b[l] - a[r] * b[r];
			if (j % 2) {
				sodd += diff;
				max = (sodd > max) ? sodd : max;
			} else {
				seven += diff;
				max = (seven > max) ? seven : max;
			}
		}
	}

	cout << max << endl;
	return 0;
}
