#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	bitset<200001> bs(1);
	int sum = 0;

	int l = 0, r = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		bs |= bs << a[i];
		sum += a[i];
	}

	if (sum % 2 || !bs[sum / 2]) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[j] % (1 << i)) {
				cout << 1 << endl << j + 1 << endl;
				return 0;
			}
		}
	}
}
