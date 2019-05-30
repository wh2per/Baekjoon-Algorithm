#include <iostream>
#include <deque>
#include <string>
using namespace std;

int bj_10866() {
	deque<int> dq;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		if (s == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (s == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (s == "pop_front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				int temp = dq.front();
				dq.pop_front();
				cout << temp << "\n";
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				int temp = dq.back();
				dq.pop_back();
				cout << temp << "\n";
			}
		}
		else if (s == "front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				int temp = dq.front();
				cout << temp << "\n";
			}
		}
		else if (s == "back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				int temp = dq.back();
				cout << temp << "\n";
			}
		}
		else if (s == "size") {
			cout << dq.size()<< "\n";
		}
		else if (s == "empty") {
			if (dq.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
	}
	return 0;
}