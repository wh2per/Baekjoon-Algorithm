#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int n, m; //가로세로
int arr[501][501];
int visit[501][501];
int ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int ans_sum = INT_MIN;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!visit[i][j] && arr[i][j]){
				++ans;

				queue<pair<int, int>> q;
				visit[i][j] = 1;
				q.push({i,j});
				int sum = 1;

				while (!q.empty())
				{
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = cx + dx[k];
						int ny = cy + dy[k];
						
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) 
							continue;
						if (visit[nx][ny]) 
							continue;
						if (arr[nx][ny] == 0) 
							continue;

						visit[nx][ny] = 1;
						q.push({nx,ny});
						++sum;
					}
				}

				ans_sum = max(sum, ans_sum);
			}
		}
	}

	if (ans_sum < 0) 
		ans_sum = 0;

	cout << ans << '\n' << ans_sum;

	return 0;
}