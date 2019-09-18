#include <iostream>
#include <vector>
using namespace std;

vector<long long> dist;
vector<int> v;

int find(int n) {
	if (n == v[n]) return n;
	int nx = find(v[n]);
	dist[n] += dist[v[n]];
	return v[n] = nx;
}

void merge(int a, int b, long long w) {
	int num1 = find(a);
	int num2 = find(b);
	if (num1 == num2)
		return;

	long long ndist = dist[a] + w - dist[b];		// 한 물체를 기준으로 무게를 수정해주자
	if (ndist > 0) {		// 나보다 무거움
		v[num2] = num1;
		dist[num2] = ndist;
	}
	else {		// 나보다 가벼움
		v[num1] = num2;
		dist[num1] = -ndist;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		dist.assign(n + 1, 0);
		v.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i)  		// 현재 자신의 수로 초기화
			v[i] = i;

		for (int i = 0; i < m; ++i) {
			char c;
			cin >> c;
			if (c == '!') {		// 실험 기록
				int x, y, w;
				cin >> x >> y >> w;
				merge(x, y, w);
			}
			else if (c == '?') {			// 교수님 질문
				int x, y;
				cin >> x >> y;
				if (find(x) != find(y))
					cout << "UNKNOWN" << '\n';
				else
					cout << dist[y] - dist[x] << "\n";
			}
		}
	}
	return 0;
}
