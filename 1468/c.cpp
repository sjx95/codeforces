#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int q;
int f[500000] = {0};

queue< pair<int, int> > nq;
priority_queue< pair<int, int> > pq;

int main() {
	cin >> q;
	int cnt = 0;
	for (int i = 0; i < q; ++i) {
		int o;
		cin >> o;
		pair<int, int> p;
		switch (o) {
			case 1:
				int v;
				cin >> v;	
				p = make_pair(v, q - cnt++);
				pq.push(p);
				nq.push(p);
				break;
			case 2:
				while (true) {
					p = nq.front();
					nq.pop();
					p.second = q - p.second;
					if (!f[p.second])
						break;
				}
				f[p.second] = true;
				cout << p.second + 1 << ' ';
				break;
			case 3:
				while (true) {
					p = pq.top();
					pq.pop();
					p.second = q - p.second;
					if (!f[p.second])
						break;
				}
				f[p.second] = true;
				cout << p.second + 1 << ' ';
				break;
		}

	}
	return 0;
}
