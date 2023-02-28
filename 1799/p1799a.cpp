#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  // cout << "n,m:" << n << ',' << m << endl;

  vector<int> posts(m);
  for (int i = 0; i < m; ++i) {
    cin >> posts[i];
  }

  vector<int> result;
  vector<int> cnt(n + m, 0);
  for (int i = 0; i < m; ++i) {
    int x = posts[i] - 1;

    if (cnt[x] == 0) {
      result.push_back(i);
      if (result.size() == n)
        break;
    }
    ++cnt[x];
  }

  for (; result.size() < n; result.push_back(-2))
    ;

  for (auto iter = result.rbegin(); iter != result.rend(); ++iter)
    cout << *iter + 1 << ' ';
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}
