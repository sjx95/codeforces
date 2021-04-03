#include <iostream>
using namespace std;

bool solve() {
	int c1, c2, c3;
	cin >> c1 >> c2 >> c3;

	int a1, a2, a3, a4, a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;

	c1 -= a1;
	c2 -= a2;
	c3 -= a3;

	if (c1 < 0 || c2 < 0 || c3 < 0)
		return false;

	a4 -= c1;
	a5 -= c2;

	return (a4>0?a4:0) + (a5>0?a5:0) <= c3;
}	

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		cout << (solve() ? "YES" : "NO") << endl;
	
	return 0;
}
