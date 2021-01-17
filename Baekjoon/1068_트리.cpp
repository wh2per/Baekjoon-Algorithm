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

const int MAX = 50;

int n, node;
pair<int, bool> parent[MAX]; //부모노드, (true: leaf가 아니다, false: leaf)
vector<int> ancestor[MAX];

int go() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < ancestor[i].size(); ++j) {
			if (ancestor[i][j] == node)
				parent[i].second = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (i != node)
			parent[parent[i].first].second = true;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (parent[i].second == false)
			++cnt;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> parent[i].first;
		parent[parent[i].first].second = true;
	}

	for (int i = 0; i < n; ++i) {
		int cur = parent[i].first;
		while (cur != -1) {
			ancestor[i].push_back(cur);
			cur = parent[cur].first;
		}
	}

	cin >> node;
	parent[node].second = true;
	parent[parent[node].first].second = false;

	cout << go();

	return 0;
}