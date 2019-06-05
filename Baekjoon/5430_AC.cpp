#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int bj_5430() {
	deque<int> dq;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string command;
		cin >> command;
		int size;
		cin >> size;
		string nums;
		cin >> nums;

		dq.clear();
		stringstream ss(nums);
		char c;
		while (ss >> c) {
			int num;
			if (ss >> num)
				dq.push_back(num);
		}

		bool r = true;
		bool flag = false;
		for (int j = 0; j < command.length(); ++j) {
			if (command[j] == 'R')
				r = !r;
			else {
				if (dq.empty()) {
					flag = true;
					break;
				}
				if (r)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (flag)
			cout << "error" << "\n";
		else {
			cout << "[";
			int c = 1;
			int ec = dq.size();
			if (r) {		// 정상
				deque<int>::iterator iter;
				for (iter = dq.begin(); iter != dq.end(); ++iter) {
					if (c == ec)
						cout << *iter;
					else {
						cout << *iter << ",";
						++c;
					}
				}
			}
			else {			// 반대로
				deque<int>::reverse_iterator riter;
				for (riter = dq.rbegin(); riter != dq.rend(); ++riter) {
					if (c == ec)
						cout << *riter;
					else {
						cout << *riter << ",";
						++c;
					}
				}
			}
			cout << "]" << "\n";
		}
	}
	
	return 0;
}