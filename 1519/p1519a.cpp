#include <cmath>
#include <iostream>
using namespace std;

void solve() {
	double r, b, d;
	cin >> r >> b >> d;

	if (r < b) { int t = r; r = b; b = t; }

	if (r <= (b * (d + 1)))
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}
