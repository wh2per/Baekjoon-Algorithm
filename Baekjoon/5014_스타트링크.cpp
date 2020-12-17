#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

vector<bool> check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	check.assign(1000001,false);

	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ s,0 });
	check[s] = true;
	bool flag = false;

	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (curr == g) {
			cout << cnt;
			return 0;
		}

		if (curr + u <= f && !check[curr + u] ) {
			q.push({ curr + u, cnt+1 });
			check[curr + u] = true;
		}
		if (curr - d > 0 && !check[curr - d] ) {
			q.push({ curr - d, cnt+1 });
			check[curr - d] = true;
		}
	}

	cout << "use the stairs";
	return 0;
}