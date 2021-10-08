#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for (int i = 0; i < n; cin >> arr[i++])
    ;

  auto ex = arr;
  sort(ex.begin(), ex.end());

  auto amin = ex[0], amax = ex[n - 1];
  for (int i = 0; i < n; ++i) {
    if (arr[i] == ex[i])
      continue;

    bool barr = i >= x || n - i > x;
    if (barr) {
      continue;
    }

    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}
