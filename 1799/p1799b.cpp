#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct element_type {
  int pos;
  int val;
  bool operator<(const element_type &a) const { return val < a.val; }
};

void solve() {
  int n;
  cin >> n;

  int64_t minVal = 1 + 1E9;
  priority_queue<element_type> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    q.push({.pos = i + 1, .val = x});
    minVal = (minVal < x) ? minVal : x;
  }

  vector<pair<int, int>> steps;

  for (;;) {
    auto i = q.top();
    if (i.val == minVal)
      break;

    q.pop();
    auto j = q.top();

    vector<int> same_pos(1, i.pos);
    while (j.val == i.val) {
      same_pos.push_back(j.pos);
      q.pop();
      j = q.top();
    }

    auto x = i;
    x.val = i.val / j.val + (i.val % j.val > 0);

    if (x.val == i.val) {
      cout << -1 << endl;
      return;
    }

    minVal = (minVal < x.val) ? minVal : x.val;
    for (auto pos : same_pos) {
      steps.push_back(make_pair(pos, j.pos));
      q.push({.pos = pos, .val = x.val});
    }
  }

  cout << steps.size() << endl;
  for (auto p : steps) {
    cout << p.first << ' ' << p.second << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}
