#include <iostream>
#include <cstdint>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int64_t a, b;
		cin >> a >> b;
		if (b == 1) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
		cout << a*(b-1) << " ";
		cout << a*(b+1) << " ";
		cout << a*b*2 << endl;
	}
	return 0;
}

