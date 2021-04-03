#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
	pair<int, int> pos;
	pair<int, int> dir;
};

int gcd(int a, int b) {	return a % b == 0 ? b : gcd(b, a % b); }

bool pc(Person a, Person b) {
	if (a.dir != b.dir) {
		return a.dir < b.dir;
	} else {
		return a.pos < b.pos;
	}
}

void solve() {
	int n;

	vector<Person> vs;
	
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		a -= x;
		b -= y;
		if (a == 0)
			a = a > 0 ? 1 : -1;
		if (b == 0)
			b = b > 0 ? 1 : -1;
		if (a * b != 0) {
			int g = gcd(abs(a), abs(b));
			if (g > 1) {
				a /= g;
				b /= g;
			}
		}
		vs.push_back(Person{.pos=make_pair(x, y), .dir=make_pair(a, b)});
	}

	sort(vs.begin(), vs.end(), pc);

	int cnt = 0;
	int l = 0, r = vs.size() - 1;
	while (l < r) {
		int lc = 1, rc = 1;
		while (vs[l + lc].dir == vs[l].dir)
			++lc;
		while (vs[r - rc].dir == vs[r].dir)
			++rc;

		int ll = l, rr = r;
		while (ll < l + lc && rr > r - rc) {
			int llc = 1, rrc = 1;
			while (ll + llc < l + lc && vs[ll + llc].pos == vs[ll].pos)
				++llc;
			while (rr - rrc > r - rc && vs[rr - rrc].pos == vs[rr].pos)
				++rrc;
			if (vs[ll].pos == vs[rr].pos) {
				cnt -= llc * rrc;
				ll += llc;
				rr -= rrc;
				continue;
			}

			pair<int, int> np = make_pair(
					vs[ll].pos.first + vs[rr].pos.first, 
					vs[ll].pos.second + vs[rr].pos.second
				);
			pair<int, int> zero = make_pair(0, 0);
			if (np > zero) {
				rr -= rrc;
			} else {
				ll += llc;
			}		
		}

		if (vs[l].dir.first + vs[r].dir.first == 0 && vs[l].dir.second + vs[r].dir.second == 0) {
			cnt += lc * rc;
			l += lc;
			r -= rc;
			continue;
		}

		pair<int, int> np = make_pair(vs[l].dir.first + vs[r].dir.first, vs[l].dir.second + vs[r].dir.second);
		pair<int, int> zero = make_pair(0, 0);
		if (np > zero) {
			r -= rc;
		} else {
			l += lc;
		}
	}
	cout << cnt << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}

