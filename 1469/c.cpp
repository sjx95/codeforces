#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve() {
	int n, k;
	cin >> n >> k;

	vector<int> hs;
	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		hs.push_back(h);
	}

	int min, max;
	for (int i = 0; i < n; ++i) {
		int h = hs[i];
		
		if (i == 0) {
			min = h - k + 1;
			max = h + k - 1;
		} else if (i == n - 1){
			if (h < min || h > max)
				return "NO";
		} else {
			if (min <= h)
				min = h;
			else if (min > h + k - 1)
				return "NO";
			if (max >= h + k - 1)
				max = h + k - 1;
			else if (max < h) 
				return "NO";
			min -= k - 1;
			max += k - 1;
		}
//		cout << "min: " << min << " max: " << max << endl;
	}
	return "YES";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) 
		cout << solve() << endl;
	return 0;
}
