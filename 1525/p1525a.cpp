#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int k;
		cin >> k;

		if (k == 0 || k == 100) {
			cout << 1 << endl;
			continue;
		}

		int e = k;
		int w = 100 - k;

		for (int j = 100; j > 1; --j) {
			if (e % j == 0 && w % j == 0) {
				e = e / j;
				w = w / j;
			}
		}

		cout << e + w << endl;
	}
}

