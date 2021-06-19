#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	string min;
	for (int i = str.size(); i > 0; --i) {
		string sub;
		while (sub.size() < k) {
			int l = k - sub.size();
			sub.append(str.substr(0, (l > i ? i : l)));
		}
		if (sub < min || !min.size())
			min = sub;
	}

	cout << min << endl;
	return 0;
}
