#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

vector<int> v;
vector<int> dist;

int find(int n) {
	if (v[n] == n)
		return n;
	int temp = find(v[n]);
	dist[n] += dist[v[n]];
	v[n] = temp;
	return v[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		v.assign(n + 1, 0);
		dist.assign(n + 1, 0);

		for (int i = 0; i <= n; ++i)
			v[i] = i;

		while (1) {
			char c;
			cin >> c;
			if (c == 'O')
				break;

			if (c == 'E') {
				int x;
				cin >> x;
				find(x);
				cout << dist[x] << "\n";
			}
			else {
				int x, y;
				cin >> x >> y;

				v[x] = y;
				int line = abs(x - y) % 1000;
				dist[x] = line;
			}
		}
	}
	return 0;
}