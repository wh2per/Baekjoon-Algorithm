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

int n, m;
bool check[2001];
vector<vector<int>> info;

void dfs(int x, int idx) {
	check[x] = true;
	if (idx == 4) {
		cout << 1;
		exit(0);
	}

	for (int i = 0; i < info[x].size(); ++i) {
		if (!check[info[x][i]])
			dfs(info[x][i],idx+1);
	}
	check[x] = false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	info.assign(n, vector<int>());

	while (m--) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		info[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) 
		dfs(i, 0);
	
	cout << 0;

	return 0;
}