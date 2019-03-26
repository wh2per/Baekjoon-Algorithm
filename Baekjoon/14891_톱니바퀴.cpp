#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> v(4, vector<int>(8, 0));

void rotate(int num, int dir) {
	if (dir == 1) {			// 시계방향
		int temp = v[num][7];
		for (int i = 7; i > 0; --i)
			v[num][i] = v[num][i - 1];
		v[num][0] = temp;
	}
	else {		// 반시계방향
		int temp = v[num][0];
		for (int i = 0; i < 7; ++i)
			v[num][i] = v[num][i + 1];
		v[num][7] = temp;
	}
}

int bj_14891() {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) 
			v[i][j] = s[j]-'0';
	}

	int n;
	cin >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		int num, dir;
		cin >> num >> dir;
		q.push(make_pair(num-1, dir));
	}

	while (!q.empty()) {
		int num = q.front().first;
		int dir = q.front().second;
		q.pop();

		vector<int> change(4,0);
		change[num] = dir;
		// 오른쪽 검사
		int rn = num;
		int right = v[num][2];
		int rdir = dir;
		while (rn + 1 < 4) {
			if (v[rn + 1][6] == right) 
				break;
			else {
				rdir *= -1;
				right = v[rn + 1][2];
				change[rn + 1] = rdir;
			}
			++rn;
		}

		// 왼쪽 검사
		int ln = num;
		int left = v[num][6];
		int ldir = dir;
		while (ln - 1 >= 0) {
			if (v[ln - 1][2] == left)
				break;
			else {
				ldir *= -1;
				left = v[ln - 1][6];
				change[ln - 1] = ldir;
			}
			--ln;
		}

		// 회전
		for (int i = 0; i < 4; i++) {
			if (change[i] != 0)
				rotate(i, change[i]);
		}
	}

	for (int i = 0; i < 4; i++) {
		ans += v[i][0]*pow(2,i);
	}

	cout << ans;

	return 0;
}