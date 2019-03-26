#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int bj_10845() {
	queue<int> q;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (str == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (str == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
		else if (str == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
	return 0;
}