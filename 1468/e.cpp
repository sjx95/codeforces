#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a[4];
		for (int i = 0; i < 4; cin >> a[i++]);
		sort(a, a+4);
		cout << a[0] * a[2] << endl;
	}
	return 0;
}
