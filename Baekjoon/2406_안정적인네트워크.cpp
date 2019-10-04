#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct node {
	int x, y, cost;
};

vector<int> parent;
vector<vector<int>> info;
vector<node> ci;


bool cmp_node(node n1, node n2) {
	if (n1.cost < n2.cost)
		return true;
	else
		return false;
}

int find(int n) {
	if (parent[n] == n)
		return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	int num1 = find(a);
	int num2 = find(b);

	if (num1 == num2)
		return;
	parent[num2] = num1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	info.assign(n+1, vector<int>(n+1, 0));
	parent.assign(n + 1, 0);

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> info[i][j];
	}

	for (int i = 2; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j)
			ci.push_back({i,j,info[i][j]});
	}
	sort(ci.begin(), ci.end(), cmp_node);

	int p1, p2;
	long long ans = 0;
	vector<pair<int, int>> answer;
	int cnt = 0;
	for (int i = 0; i < ci.size(); ++i) {
		
		p1 = find(ci[i].x);
		p2 = find(ci[i].y);

		if (p1 == p2)
			continue;

		parent[p2] = p1;
		ans += ci[i].cost;
		answer.push_back({ci[i].x, ci[i].y});
	}
	cout << ans << " "<<answer.size()<<"\n";
	for (auto a : answer)
		cout << a.first << " " << a.second << "\n";
	return 0;
}