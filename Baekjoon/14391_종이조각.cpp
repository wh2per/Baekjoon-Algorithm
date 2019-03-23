#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int Np, Mp;
int ans_paper;
vector<vector<int>> check_paper;
vector<vector<int>> map_paper;

void dfs_paper(int n, int m) {
	if (n==Np-1 && m==Mp-1) {		// 종료
		vector<vector<bool>> visit(Np,vector<bool>(Mp,false));
		int ans_temp=0;
		for (int a = 0; a < Np; a++) {
			for (int b = 0; b < Mp; b++) {
				if (!visit[a][b]) {
					int temp = 0;
					if (check_paper[a][b] == 0) {		// 가로
						int tb = b;
						while (tb<Mp && visit[a][tb] == false && check_paper[a][tb] == 0) {
							visit[a][tb] = true;
							temp *= 10;
							temp += map_paper[a][tb];
							tb++;
						}
					}
					else {						// 세로
						int ta = a;			
						while (ta<Np && visit[ta][b] == false && check_paper[ta][b] == 1) {
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
	if (m < Mp-1) {
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
	cin >> Np >> Mp;
	map_paper.resize(Np, vector<int>(Mp, -1));
	check_paper.resize(Np, vector<int>(Mp, -1));

	for (int i = 0; i < Np; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < Mp; j++) {
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