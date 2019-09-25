#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// 위상정렬
vector<int> v;

int find(int n) {
	if (v[n] == n)
		return n;
	return v[n] = find(v[n]);
}

void merge(int a, int b) {
	if (a > b)
		swap(a, b);
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	v[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> info(n);

	v.assign(n, 0);

	for (int i = 0; i < n; ++i)		// 초기화
		v[i] = i;

	for (int i = 0; i < m; ++i) {
		int k, l;
		char s;
		cin >> k >> s >> l;

		if (s == '>') 
			info[k].push_back(l);		// 나한테 지는 애들을 저장
		else
			merge(l, k);				// 같은 실력끼리 묶어주기
	}

	map<int, set<int>> ninfo;			// 새로운 info
	for (int i = 0; i < n; ++i) {
		set<int> temp;
		ninfo.insert({i,temp});
	}
	vector<int> ndegree(n, 0);			// 새로운 차수

	bool flag = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < info[i].size(); ++j) {
			int lose = find(info[i][j]);			// 나한테 지는 애
			int win = find(i);
			if (lose == win) {			// 자기 자신에게 진다 = 사이클
				cout << "inconsistent";
				return 0;
			}
			if (ninfo[win].count(lose) == 0)
				++ndegree[lose];
			ninfo[win].insert(lose);
		}
	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (ndegree[i] == 0)
			q.push(i);
	}

	int ans = 0;
	while (!q.empty()) {
		int d = q.front();
		q.pop();

		++ans;
		for (auto a : ninfo[d]) {
			--ndegree[a];
			if (ndegree[a] == 0)
				q.push(a);
		}
	}

	if ( ans != n)
		cout << "inconsistent";
	else
		cout << "consistent";

	return 0;
}