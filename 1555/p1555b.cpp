#include <cstdint>
#include <iostream>
using namespace std;

void solve() {
	int tw, th;
	cin >> tw >> th;

	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int w2, h2;
	cin >> w2 >> h2;

	bool fw = x2 - x1 + w2 <= tw;
	bool fh = y2 - y1 + h2 <= th;

	if (!fw && !fh) {
		cout << -1 << endl;
		return;
	}

	int ret = max(tw, th);
	if (fw) {
		ret = min(ret, max(w2 - x1, 0));
		ret = min(ret, max(w2 - (tw - x2), 0)); 
	}
	if (fh) {
		ret = min(ret, max(h2 - y1, 0));
		ret = min(ret, max(h2 - (th - y2), 0));
	}

	cout << ret << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) 
		solve();
	return 0;
}
