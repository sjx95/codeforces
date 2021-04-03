#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

int64_t arr[100000];
int64_t dt[100000];

int64_t wd(int64_t a, int x) {
	int64_t ret = 0;
	while (a % x == 0) {
		++ret;
		a /= x;
	}
	return ret;
}

int64_t solve() {
	int n, x;
	cin >> n >> x;

	int64_t min = INT64_MAX;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dt[i] = wd(arr[i], x);
		min = std::min(min, dt[i]);
	}

	int64_t sum = 0;
	int flag = 1;
	for (int i = 0; i < n; ++i) {
		if (dt[i] == min)
			flag = 0;
		sum += arr[i] * (1 + min + flag);
	}
	return sum;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		cout << solve() << endl;
	return 0;
}
