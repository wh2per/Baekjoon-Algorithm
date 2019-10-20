#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> parent;
vector<vector<int>> arr;
vector<vector<bool>> check;

const int dx[] = {0,1, 0 ,-1,1,1,-1,-1};
const int dy[] = {1,0, -1, 0,-1,1,1,-1};

int main() {
	freopen("input.txt", "r", stdin);

	int h, w;
	while (1) {
		cin >> w >> h;

		if (h == 0 && w == 0)
			break;
		arr.assign(h, vector<int>(w, 0));
		check.assign(h, vector<bool>(w, false));

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				cin >> arr[i][j];
		}

		int num = 0;
		for (int i = 0; i < h; ++i) {				// ±×·ìÈ­
			for (int j = 0; j < w; ++j) {
				if (arr[i][j] == 1 && !check[i][j]) {
					queue<pair<int, int>> q;
					check[i][j] = true;
					q.push({ i,j });

					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int k = 0; k < 8; ++k) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx >= w || nx < 0 || ny >= h || ny < 0 || check[ny][nx] || arr[ny][nx]==0)
								continue;
							q.push({ ny,nx });
							check[ny][nx] = true;
						}
					}
					++num;
				}
			}
		}
		
		cout << num << "\n";
	}

	return 0;
}