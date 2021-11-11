#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dist[100001];
int cost[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	cin >> n;

	for (int i = 1; i < n; ++i) {
		cin >> dist[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
	}

	long long now = cost[0];
	long long ans = now * dist[1];

	for (int i = 1; i < n; ++i) {
		if (now >= cost[i])
			now = cost[i];
		ans += now * dist[i + 1];
	}
	cout << ans;
	return 0;
}