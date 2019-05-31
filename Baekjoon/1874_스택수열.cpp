#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int bj_1874() {
	stack<int> s;
	vector<char> ans;
	int n; 
	cin >> n;
	int start = 1;
	int count = n;
	for (int i = 0; i < n; ++i) {
		int target;
		cin >> target;

		while (count>=0 && (s.empty() || s.top() != target)) {
			s.push(start++);
			ans.push_back('+');
			--count;
		}
		if (count < 0) {
			cout << "NO";
			return 0;
		}
		s.pop();
		ans.push_back('-');
	}
	for (auto a : ans)
		cout << a << '\n';
	return 0;
}