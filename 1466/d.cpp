#include <cstdint>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int64_t, int> w[100000];
set<int> edge[100000];

void solve() {
	int n;
	cin >> n;
	int64_t ret = 0;

	for (int i = 0; i < n; ++i) {
		cin >> w[i].first;
		w[i].second = i;
		edge[i].clear();
		ret += w[i].first;
	}

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		edge[a-1].insert(b-1);
		edge[b-1].insert(a-1);
	}

	cout << ret << ' ';
	
	sort(w, w+n);
	for (int i = 0; i < n; ++i) {
		int pos = w[i].second;
		if (edge[i].size() <= 1) 
			continue;

		int op = *edge[pos].begin();
		edge[pos].erase(op);
		edge[op].erase(pos);

		cout << "[" << w[i].second+1 << "]";
		ret += w[i--].first;
		cout << ret << ' ';
	}

	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
