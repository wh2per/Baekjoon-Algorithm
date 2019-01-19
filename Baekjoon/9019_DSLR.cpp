#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int bj_9019() {
	const int MAX = 10000;
	bool check[MAX + 1];
	int dist[MAX + 1];
	char how[MAX + 1];
	int from[MAX + 1];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		queue<int> q;
		int start;
		int end;
		cin >> start >> end;

		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(how, 0, sizeof(how));
		memset(from, 0, sizeof(from));

		check[start] = true;
		dist[start] = 0;
		from[start] = -1;
		q.push(start);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			int temp = (now * 2) % 10000;
			if (check[temp] == false) {
				q.push(temp);
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				how[temp] = 'D';
			}
			temp = now - 1;
			if (temp == -1)	temp = 9999;
			if (check[temp] == false) {
				q.push(temp);
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				how[temp] = 'S';
			}

			temp = (now % 1000) * 10 + now / 1000;
			if (check[temp] == false) {
				q.push(temp);
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				how[temp] = 'L';
			}

			temp = (now / 10) + (now % 10) * 1000;
			if (check[temp] == false) {
				q.push(temp);
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				how[temp] = 'R';
			}
		}

		string ans = "";
		while (end != start) {
			ans += how[end];
			end = from[end];
		}
		reverse(ans.begin(), ans.end());

		cout << ans << '\n';
	}

	return 0;
}