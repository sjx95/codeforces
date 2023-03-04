#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {

		int n, k;
		cin >> n >> k;

		int a[100];
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
		}

		for (int j = 0; j < n - 1; ++j) {
			if (a[j] < k) {
				a[n-1] += a[j];
				k -= a[j];
				a[j] = 0;
			} else {
				a[n-1] += k;
				a[j] -= k;
				k = 0;
			}
		}

		for (int j = 0; j < n; ++j) {
			cout << a[j] << " ";
		}

		cout << endl;
		
	}
	
}
