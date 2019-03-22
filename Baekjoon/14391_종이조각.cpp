#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int N, M;
int ans_paper;
vector<vector<int>> check_paper;
vector<vector<int>> map_paper;

void dfs_paper(int n, int m) {
	if (n==N-1 && m==M-1) {		// 종료
		vector<vector<bool>> visit(N,vector<bool>(M,false));
		int ans_temp=0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				if (!visit[a][b]) {
					int temp = 0;
					if (check_paper[a][b] == 0) {		// 가로
						int tb = b;
						while (tb<M && visit[a][tb] == false && check_paper[a][tb] == 0) {
							visit[a][tb] = true;
							temp *= 10;
							temp += map_paper[a][tb];
							tb++;
						}
					}
					else {						// 세로
						int ta = a;			
						while (ta<N && visit[ta][b] == false && check_paper[ta][b] == 1) {
							visit[ta][b] = true;
							temp *= 10;
							temp += map_paper[ta][b];
							ta++;
						}
					}
					ans_temp += temp;
				}
			}
		}
		if (ans_temp > ans_paper)
			ans_paper = ans_temp;

		return;
	}
	if (m < M-1) {
		m++;
		check_paper[n][m] = 0;
		dfs_paper(n, m);		// 0으로 선택
		check_paper[n][m] = 1;
		dfs_paper(n, m);		// 1로 선택
	}
	else {
		n++;
		m = 0;
		check_paper[n][m] = 0;
		dfs_paper(n, m);		// 0으로 선택
		check_paper[n][m] = 1;
		dfs_paper(n, m);		// 1로 선택
	}
}

int bj_14391() {
	ans_paper = INT_MIN;
	cin >> N >> M;
	map_paper.resize(N, vector<int>(M, -1));
	check_paper.resize(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map_paper[i][j] = s[j]-'0';
		}
	}

	check_paper[0][0] = 0;
	dfs_paper(0, 0);
	check_paper[0][0] = 1;
	dfs_paper(0, 0);

	cout << ans_paper;
	return 0;
}