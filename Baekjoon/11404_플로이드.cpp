#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 플로이드 와샬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;

	vector<vector<int>> info(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (info[a][b] != 0)
			info[a][b] = min(info[a][b], c);
		else
			info[a][b] = c;
	}

	for (int i = 1; i <= n; ++i) {		// 경유
		for (int j = 1; j <= n; ++j) {	// 시작점
			if (info[j][i] == 0)		//  시작-경유 가는길이 없으면
				continue;
			for (int k = 1; k <= n; ++k) { 	// 도착점
				if (info[i][k] == 0 || j == k)			// 경유-도착 가는길이 없거나 시작=도착이면
					continue;
				if(info[j][k]==0 || info[j][k] > info[j][i] + info[i][k])		// 시작-도착 길이 없거나 경유하는 것보다 클때
					info[j][k]= info[j][i] + info[i][k];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)  	// 시작점
			cout << info[i][j] << " ";
		cout << "\n";
	}

	return 0;
}