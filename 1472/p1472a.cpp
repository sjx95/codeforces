#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int w, h, n;
		cin >> w >> h >> n;
		int wd, hd;
		for (wd = 1; w % wd == 0; wd *= 2);
		for (hd = 1; h % hd == 0; hd *= 2);
		int max = wd * hd / 4;
		cout << (n <= max ? "YES" : "NO") << endl;
	}
	return 0;
}
