#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int bj_10828() {
	stack<int> s;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (str == "top") {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
		else if (str == "pop") {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (str == "size") {
			cout << s.size() << '\n';
		}
		else if (str == "empty") {
			if (s.empty())
				cout << 1 << '\n';
			else 
				cout << 0 << '\n';
		}
	}
	return 0;
}