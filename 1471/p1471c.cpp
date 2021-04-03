#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

int k[300000], c[300000];

int64_t solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; cin >> k[i++]);
	for (int i = 0; i < m; cin >> c[i++]);
	for (int i = 0; i < n; --k[i++]);
	sort(k, k + n);
	int64_t sum = 0;
	int used = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (used <= k[i])
			sum += c[used++];
		else 
			sum += c[k[i]];
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
