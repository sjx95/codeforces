#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  vector<int64_t> cold(k);
  for (int i = 0; i < k; ++i)
    cin >> cold[i];

  vector<int64_t> hot(k);
  for (int i = 0; i < k; ++i)
    cin >> hot[i];

  vector<vector<int64_t>> data(n, vector<int64_t>(k + 1, 1e15));
  data[0][k] = cold[a[0]];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      int64_t x =
          data[i - 1][j] + ((a[i] == a[i - 1]) ? hot[a[i]] : cold[a[i]]);
      data[i][j] = min(data[i][j], x);
    }

    vector<int64_t> buf(k + 1);
    for (int j = 0; j <= k; ++j) {
      buf[j] = data[i - 1][j] + ((j == a[i]) ? hot[a[i]] : cold[a[i]]);
    }
    data[i][a[i - 1]] =
        min(data[i][a[i - 1]], *min_element(buf.begin(), buf.end()));
  }

  for (int i = 0; i < n; ++i) {
	  break;
    for (int j = 0; j < k; ++j)
      cout << data[i][j] << ' ';
    cout << endl;
  }

  cout << *min_element(data[n - 1].begin(), data[n - 1].end()) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
}
