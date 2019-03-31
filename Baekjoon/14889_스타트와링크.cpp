#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int bj_14889() {
	int ans = INT_MAX;
	int N;
	cin >> N;
	vector<vector<int>> score(N+1,vector<int>(N+1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			cin >> score[i][j];
	}

	vector<int> v(N, 1);
	for (int i = 0; i < N/2; i++)
		v[i] = 0;
	
	do {
		int score1 = 0;
		int score2 = 0;

		vector<int> start;
		vector<int> link;
		for (int i = 0; i < N; ++i) {
			if (v[i] == 0) 
				start.push_back(i + 1);
			else 
				link.push_back(i + 1);
		}

		for (int i = 0; i < (N / 2) - 1; ++i) {
			for (int j = i + 1; j < N / 2; ++j) {
				score1 += score[start[i]][start[j]];
				score1 += score[start[j]][start[i]];
				score2 += score[link[i]][link[j]];
				score2 += score[link[j]][link[i]];
			}
		}

		if (abs(score1 - score2) < ans)
			ans = abs(score1 - score2);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
	return 0;
}