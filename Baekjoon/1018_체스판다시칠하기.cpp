#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	
using namespace std;

int bj_1018() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> v(N,vector<char>(M));
	vector<vector<char>> b = { { 'B','W','B','W' ,'B','W' ,'B','W' },
							{ 'W','B','W' ,'B','W' ,'B','W','B' },
							{ 'B','W','B','W' ,'B','W' ,'B','W' },
							{ 'W','B','W' ,'B','W' ,'B','W','B' },
							{ 'B','W','B','W' ,'B','W' ,'B','W' },
							{ 'W','B','W' ,'B','W' ,'B','W','B' },
							{ 'B','W','B','W' ,'B','W' ,'B','W' },
							{ 'W','B','W' ,'B','W' ,'B','W','B' } };
	vector<vector<char>> w = { { 'W','B','W' ,'B','W' ,'B','W','B' },
							{ 'B','W','B','W' ,'B','W' ,'B','W' },
							{ 'W','B','W' ,'B','W' ,'B','W','B' },
							{ 'B','W','B','W' ,'B','W' ,'B','W' },
							{ 'W','B','W' ,'B','W' ,'B','W','B' },
							{ 'B','W','B','W' ,'B','W' ,'B','W' },
							{ 'W','B','W' ,'B','W' ,'B','W','B' },
							{ 'B','W','B','W' ,'B','W' ,'B','W' } };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) 
			cin >> v[i][j];
	}

	int ans = 65;

	// 브루트 포스
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int tw = 0;
			int tb = 0;
			int tans = 0;
			// 첫 판 블랙
			for (int n = 0; n < 8; n++) {
				for (int m = 0; m < 8; m++) {
					if (b[n][m] != v[i+n][j+m]) {
						tb++;
					}
				}
			}
			// 첫 판 화이트
			for (int n = 0; n < 8; n++) {
				for (int m = 0; m < 8; m++) {
					if (w[n][m] != v[i+n][j+m]) {
						tw++;
					}
				}
			}
			tans = min(tb, tw);
			if (ans > tans)
				ans = tans;
		}
	}

	cout << ans;
	return 0;
}