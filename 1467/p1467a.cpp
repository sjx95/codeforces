#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		
		int x = 9;
		for (int j = 0; j < n; ++j) {
			cout << x;
			if (j < 1)
				x = (x + 10 - 1) % 10;
			else
				x = ++x % 10;
		}
		cout << endl;
	}
	return 0;
}
