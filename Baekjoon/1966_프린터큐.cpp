#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bj_1966() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int N, M;
		cin >> N >> M;
		queue<pair<int, int>> q;		// <prior, name>
		vector<int> p;
		int a = 1;
		int b = 0;

		for (int j = 0; j < N; ++j) {
			int prior;
			cin >> prior;
			q.push({prior,a});
			p.push_back(prior);
			if (j == M)
				b = a;
			++a;
		}
		sort(p.begin(), p.end(), greater<int>());
		
		for (int k = 0; k < p.size(); ++k) {
			while (q.front().first != p[k]) {		// 찾는 prior가 아니라면 뒤로 보내자
				q.push(q.front());
				q.pop();
			}
			if (q.front().second == b) {
				cout << k + 1 << '\n';
				break;
			}
			q.pop();
		}
	}
	return 0;
}