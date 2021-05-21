#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

uint64_t solve() {
	int n;
	cin >> n;

	map<int64_t, vector<int64_t>> m;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (m.find(x) == m.end())
			m[x] = vector<int64_t>();
		m[x].push_back(i);
	}

	int64_t cnt = 0;
	for (auto &_pair : m) {
		auto &ps = _pair.second;

		int64_t sum = 0;
		for (auto &x : ps)
			sum += x;

		for (int64_t i = 0; i < ps.size(); ++i) {
			sum -= ps[i];
			cnt += (1 + ps[i]) * ((ps.size() - i - 1) * n - sum);
		}
		
	}

	return cnt;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		cout << solve() << endl;
	return 0;
}

