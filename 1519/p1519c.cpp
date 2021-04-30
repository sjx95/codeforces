#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> arr[n];
	vector<int64_t> sarr[n];

	int64_t sum = 0;
	int u[n];
	for (int i = 0; i < n; scanf("%d", &u[i++]));
	for (int i = 0; i < n; ++i) {
		int s;
		scanf("%d", &s);
		sum += s;
		arr[u[i] - 1].push_back(s);
	}

	list<int> ne;
	for (int i = 0; i < n; ++i) {
		if (arr[i].size() > 0)
			ne.push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		sort(arr[i].begin(), arr[i].end());
	}

	for (int i = 1; i <= n; ++i) {
		int64_t ex = 0;
		for (auto iter = ne.begin(); iter != ne.end(); ++iter) {
			auto j = *iter;
			int p = arr[j].size() % i;
			if (p == 0)
				continue;
			else
				--p;

			if (p >= arr[j].size())
				p = arr[j].size() - 1;

			if (sarr[j].size() == 0)
				sarr[j].push_back(arr[j][0]);

			for (int k = sarr[j].size(); k <= p; ++k)
				sarr[j].push_back(sarr[j][k-1] + arr[j][k]);

			if (arr[j].size() / i) {
				ex += sarr[j][p]; 
			} else {
				sum -= sarr[j][p];
				iter = --ne.erase(iter);
			}
		}
		cout << sum - ex << " ";
		if (sum == ex) {
			for (int j = i + 1; j <= n && sum == ex; ++j) 
				cout << 0 << " ";
			return;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) 
		solve();
}
