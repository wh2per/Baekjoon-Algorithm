#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

struct cmp_fish {
	bool operator()(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) {
		if (p1.second == p2.second) {
			if (p1.first.first == p2.first.first) {
				if (p1.first.second > p2.first.second)
					return false;
				else
					return true;
			}
			else {
				if (p1.first.first > p2.first.first)
					return false;
				else
					return true;
			}
		}
		else {
			if (p1.second > p2.second)
				return false;
			else
				return true;
		}
	}
};

int bj_16236() {
	int time = 0;
	int N;
	int my, mx;
	int msize = 2;
	int hungry = 0;
	cin >> N;
	vector<vector<int>> sea(N, vector<int>(N));
	map<pair<int, int>, int> fish;		// <y,x>, siez

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> sea[i][j];
			if (sea[i][j] == 9) {
				my = i;
				mx = j;
			}
			else if (sea[i][j] != 0) {		// 0,9 가 아니면 모두 물고기
				fish.insert({ {i,j},sea[i][j] });
			}
		}
	}

	while (1) {
		vector<vector<bool>> check(N, vector<bool>(N, false));
		vector<pair<int, int>> v;		// 목적지 목록
		// 내 사이즈 기준으로 큰 사이즈는 모두 못지나가는 영역으로 변환
		for (auto a : fish) {
			if (a.second > msize)
				check[a.first.first][a.first.second] = true;
			else if (a.second < msize)		// 나보다 작은 물고기는 모두 목적지 목록에 추가
				v.push_back(a.first);
		}

		vector<pair<pair<int, int>, int>> dest;		// 목적지와 목적지까지의 거리
		int min = INT_MAX;
		for (int i = 0; i < v.size(); ++i) {
			queue<pair<pair<int, int>, int>> q;		// 내 위치, 이동한거리
			q.push({ { my, mx }, 0 });
			vector<vector<bool>> c(check.begin(), check.end());
			c[my][mx] = true;
			while (!q.empty()) {
				int y = q.front().first.first;
				int x = q.front().first.second;
				int dist = q.front().second;
				q.pop();
				
				if (dist > min)
					break;
				if (y == v[i].first && x == v[i].second) {		// 목적지 도착
					dest.push_back({ {y,x},dist });
					if (min > dist)
						min = dist;
					break;
				}

				for (int k = 0; k < 4; ++k) {
					int ky = y + dy[k];
					int kx = x + dx[k];

					if (ky < 0 || ky >= N || kx < 0 || kx >= N)
						continue;
					if (!c[ky][kx]) {
						c[ky][kx] = true;
						q.push({ {ky,kx},dist + 1 });
					}
				}
			}
		}

		if (dest.size() == 0)
			break;

		sort(dest.begin(), dest.end(), cmp_fish());		// 거리 짧은 순, x가 왼쪽 순으로 정렬

		my = dest[0].first.first;		// 내 위치 이동
		mx = dest[0].first.second;
		++hungry;						// 먹고
		if (hungry == msize) {			// 배가 차면
			++msize;					// 크기 증가
			hungry = 0;
		}

		time += dest[0].second;			// 시간 증가

		fish.erase({my,mx});			// 물고기 제거
	}
	
	cout << time;
	return 0;
}
