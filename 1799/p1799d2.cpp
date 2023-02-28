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

  vector<int64_t> dp(k + 1, 1e15);
  int64_t bias = 0, min_dp = 1e15;
  min_dp = dp[k] = cold[a[0]];
  for (int i = 1; i < n; ++i) {
    int64_t x = min(bias + min_dp + cold[a[i]], bias + dp[a[i]] + hot[a[i]]);
    bias += (a[i] == a[i - 1]) ? hot[a[i]] : cold[a[i]];
    dp[a[i - 1]] = min(dp[a[i - 1]], x - bias);
    min_dp = min(min_dp, dp[a[i - 1]]);
  }

  cout << bias + *min_element(dp.begin(), dp.end()) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
}
