#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

vector<vector<int>> arr;
vector<vector<long long>> dist;

// 벨만 포드
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int w, h, g;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		pair<int, pair<int, int>> info[31][31] = { {{0,{0,0}},} };
		arr.assign(h, vector<int>(w, 0));		// 맵 세팅
		dist.assign(h, vector<long long>(w, INT64_MAX));

		cin >> g;
		for (int i = 0; i < g; ++i) {
			int x, y;
			cin >> x >> y;
			arr[h - y - 1][x] = 1;					// 묘비 세팅
		}

		int e;
		cin >> e;

		for (int i = 0; i < e; ++i) {
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			arr[h - y1 - 1][x1] = 2;				// 귀신 구멍 세팅

			info[h - y1 - 1][x1] = { t,{h - y2 - 1, x2} };
		}

		// 출발 arr[h-1][0]  도착 arr[0][w-1]
		dist[h - 1][0] = 0;		// 시작점 초기화
		bool flag = false;
		for (int i = 1; i <= w*h; ++i) {				// 사용할 간선 n-1만큼 돌려보기
			for (int j = 0; j < h; ++j) {			// 정점 1~N까지 돌려보기
				for (int k = 0; k < w; ++k) {
					if (dist[j][k] == INT64_MAX)		// 출발점이 아직 갱신된 곳이 아니라면 스킵
						continue;
					if (j == 0 && k == w - 1)			//  도착지점에서는 검사 X
						continue;
					if (arr[j][k] == 1)					//  묘비는 스킵
						continue;
					else if (arr[j][k] == 2) {				// 귀신 구멍이라면 4방향 검사 X
						int gy = info[j][k].second.first;
						int gx = info[j][k].second.second;
						int gcost = info[j][k].first;
						if (dist[gy][gx] > dist[j][k] + gcost) {
							if (i != w*h) 
								dist[gy][gx] = dist[j][k] + gcost;
							else	// N번째 간선때 값이 갱신되면 음수사이클 존재
								flag = true;
						}
					}
					else {				// 일반 잔디일 경우
						for (int d = 0; d < 4; ++d) {		// 정점에서 갈 수 있는 곳
							int ny = j + dy[d];
							int nx = k + dx[d];

							if (ny >= h || ny < 0 || nx >= w || nx < 0 || arr[ny][nx] == 1)		// 맵을 벗어나거나 묘지
								continue;

							if (dist[ny][nx] > dist[j][k] + 1) {			// 걸어갈 때
								if (i != w*h)
									dist[ny][nx] = dist[j][k] + 1;
								else										// N번째 간선때 값이 갱신되면 음수사이클 존재
									flag = true;
							}
						}
					}
				}
			}
		}
		if (flag)
			cout << "Never\n";
		else {
			if (dist[0][w-1]== INT64_MAX)
				cout << "Impossible\n";
			else
				cout << dist[0][w - 1] << "\n";
		}
	}
	return 0;
}