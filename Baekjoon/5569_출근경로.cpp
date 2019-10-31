#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// 첫 번째 인자가 0인 경우 동쪽으로 이동, 1인 경우 북쪽으로 이동
// 두 번째 인자가 0인 경우 현재 방향으로 1칸만 이동, 1인 경우 2칸 이상 이동
int dp[110][110][2][2]; //dir, 1 or over2
const int m = 100000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int w, h;
	cin >> w >> h;


	for (int i = 2; i <= w; i++) 
		dp[i][1][0][1] = 1;
		
	for (int i = 2; i <= h; i++) 
		dp[1][i][1][1] = 1;
	

	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			// 동쪽으로 1칸 움직인 애 = 내 왼쪽이고 북쪽으로 2칸 이상 움직여서 온 애
			dp[i][j][0][0] = dp[i-1][j][1][1];
			// 동쪽으로 2칸이상 움직인 애= 왼쪽에서 동쪽으로 1칸, 2칸이상 온 애
			dp[i][j][0][1] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1])%m;
			// 북쪽으로 1칸 움직인 애 = 내 아래쪽이고 동쪽으로 2칸 이상 움직여서 온 애
			dp[i][j][1][0] = dp[i][j-1][0][1];
			// 북쪽으로 2칸이상 움직인 애 = 아래쪽에서 북쪽으로 1칸, 2칸이상 온 애
			dp[i][j][1][1] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1])%m;
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			ans += dp[w][h][i][j];
	}

	cout << ans % m;

	return 0;
}