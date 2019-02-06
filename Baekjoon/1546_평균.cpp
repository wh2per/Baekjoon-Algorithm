#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_1546() {
	int N;
	cin >> N;
	vector<float> score(N);
	for (int i = 0; i < N; i++)
		cin >> score[i];

	sort(score.begin(), score.end());
	float M = score[N - 1];
	float ans = 0;

	for (auto i : score)
		ans += i * 100 / M;

	cout << ans / N;
	return 0;
}