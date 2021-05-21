#include <iostream>
#include <string>
using namespace std;

string solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int cntn = 0;
	int cnts = 0;
	for (int i = 0; i < str.size(); ++i) {
		auto p = str.begin() + i;
		auto r = str.rbegin() + i;

		cnts += (*p == '0' && *r == '0');
		cntn += (*p == '0' && *r != '0');
	}

	if (cnts == 1 && cntn == 1)
		return "DRAW";

	if (!cntn) {
		if (cnts == 1)
			return "BOB";
		else
			return cnts % 2 ? "ALICE" : "BOB";
	} else 
		return "ALICE";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		cout << solve() << endl;
	return 0;
}

