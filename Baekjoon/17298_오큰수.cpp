#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int bj_17298() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> ans(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	stack<int> s;
	s.push(INT_MAX);
	for (int i = n - 1; i >= 0; --i) {
		while (s.top() <= v[i])
			s.pop();
		if (s.top() >= INT_MAX)
			ans[i] = -1;
		else
			ans[i] = s.top();
		s.push(v[i]);
	}
	for (auto i : ans)
		cout << i << " ";
	return 0;
}