#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <queue>
using namespace std;

int n;
char arr[101][101];
bool check1[101][101];
bool check2[101][101];
queue<pair<pair<int, int>, char>> q;

const int dx[] = { 1,0,-1,0 };		// 오른쪽, 아래, 왼쪽, 위
const int dy[] = { 0,1,0,-1 };

int bfs1() {
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!check1[i][j]) {
				check1[i][j] = true;
				++ans;
				q.push({ { i,j },arr[i][j] });
				while (!q.empty()) {
					int cy = q.front().first.first;
					int cx = q.front().first.second;
					char cc = q.front().second;
					q.pop();

					for (int k = 0; k < 4; ++k) {
						int ny = cy + dy[k];
						int nx = cx + dx[k];

						if (ny<0 || ny>n || nx<0 || nx>n || check1[ny][nx] || arr[ny][nx] != cc)
							continue;
						check1[ny][nx] = true;
						q.push({ {ny,nx}, cc });
					}
				}
			}
		}
	}

	return ans;
}

int bfs2() {
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!check2[i][j]) {
				check2[i][j] = true;
				++ans;
				q.push({ { i,j },arr[i][j] });
				while (!q.empty()) {
					int cy = q.front().first.first;
					int cx = q.front().first.second;
					char cc = q.front().second;
					q.pop();

					for (int k = 0; k < 4; ++k) {
						int ny = cy + dy[k];
						int nx = cx + dx[k];

						if (ny<0 || ny>n || nx<0 || nx>n || check2[ny][nx])
							continue;
						if (cc == 'R' || cc == 'G') {
							if (arr[ny][nx] == 'B')
								continue;
						}
						else {
							if (cc != arr[ny][nx])
								continue;
						}
						check2[ny][nx] = true;
						q.push({ {ny,nx}, arr[ny][nx] });
					}
				}
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}


	cout << bfs1() << " "<<bfs2();

	return 0;
}