#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int bj_2493() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	stack<pair<int, int>> s;
	for (int i = 0; i < N; ++i) {
		int h;
		cin >> h;
		while (!s.empty()) {
			if (s.top().second > h) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty())
			cout << 0 << " ";
		s.push({ i + 1,h });
	}
	return 0;
}