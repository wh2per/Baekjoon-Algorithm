#include <iostream>
#include <queue>
using namespace std;

int dist[200001];            
bool check[200001];
long long cnt[200001];

int bj_12851() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	dist[n] = 0;
	cnt[n] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : {now - 1, now + 1, now * 2}) {
			if (next >= 0 && next <= 200001) {
				if (check[next] == false) {
					q.push(next);
					check[next] = true;
					dist[next] = dist[now] + 1;
					cnt[next] = cnt[now];
				}
				else if (dist[next] == dist[now] + 1) {
					cnt[next] += cnt[now];
				}
			}
		}
	}
	cout << dist[k] << '\n';
	cout << cnt[k] << '\n';
	return 0;
}