#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int bj_11729() {
	vector<vector<int>> answer;
	int n;
	cin >> n;
	stack<int> s;							// 2. 비재귀 
	int from = 1;
	int by = 2;
	int to = 3;
	while (1) {
		while (n > 1) {
			s.push(to);    // 인자리스트 푸쉬
			s.push(by);
			s.push(from);
			s.push(n);
			n--;        // 인자리스트 변경 1
			s.push(to);    // to 와 by를 교환하기 위해 임시로 저장
			to = by;
			by = s.top();
			s.pop();
		}

		vector<int> v;
		v.push_back(from);
		v.push_back(to);
		answer.push_back(v);

		if (!s.empty()) {
			n = s.top();
			s.pop();
			from = s.top();
			s.pop();
			by = s.top();
			s.pop();
			to = s.top();
			s.pop();

			vector<int> v;
			v.push_back(from);
			v.push_back(to);
			answer.push_back(v);

			n--;        // 인자리스트 변경 2
			s.push(from);
			from = by;
			by = s.top();
			s.pop();
		}
		else {
			break;
		}
	}

	cout << answer.size() << '\n';
	for (auto a : answer) {
		cout << a[0] << " " << a[1] << '\n';
	}

	return 0;
}