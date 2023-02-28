#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  string prefix, suffix;
  for (auto iter = s.begin(); iter != s.end();) {
    if (iter + 1 == s.end()) {
      prefix.push_back(*(iter++));
    } else if (*iter == *(iter + 1)) {
      prefix.push_back(*(iter++));
      suffix.push_back(*(iter++));
    } else if (*(iter + 1) == *s.rbegin()) {
      prefix.append((s.end() - iter) / 2, *s.rbegin());
      prefix.push_back(*(iter++));
      suffix.append((s.end() - iter) / 2, *s.rbegin());
      iter = s.end();
    } else {
      suffix.push_back(*(iter++));
      prefix.append(iter, s.end());
      iter = s.end();
    }
  }

  string result = prefix;
  result.append(suffix.rbegin(), suffix.rend());
  cout << result << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
}
