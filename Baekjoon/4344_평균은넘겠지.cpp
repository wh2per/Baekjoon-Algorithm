#include <iostream>
#include <vector>
using namespace std;

int bj_4344(){
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;
		float score = 0;
		float cnt = 0;
		vector<int> scores(N);
		for (int j = 0; j < N; j++) {
			cin >> scores[j];
			score += scores[j];
		}
		score = score / N;
		for (int k = 0; k < N; k++) {
			if (scores[k] > score)
				cnt++;
		}
		cout << fixed;
		cout.precision(3);
		cout << cnt * 100 /N << "%"<<endl;
	}
	return 0;
}