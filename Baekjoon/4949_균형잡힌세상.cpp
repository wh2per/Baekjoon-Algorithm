#include <iostream>
#include <string>
#include <stack>
using namespace std;

int bj_4949() {
	while (1) {
		string str;
		getline(cin, str);		// 띄어쓰기 포함 입력
		if (str == ".") {
			break;
		}

		bool flag = true;
		stack<char> s;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == ')') {
				if (s.empty()) {
					flag = false;
					break;
				}
				else {
					if (s.top() == '(') {
						s.pop();
					}
					else {
						flag = false;
						break;
					}
				}
			}
			else if (str[i] == ']') {
				if (s.empty()) {
					flag = false;
					break;
				}
				else {
					if (s.top() == '[') {
						s.pop();
					}
					else {
						flag = false;
						break;
					}
				}
			}
			else if (str[i] == '(') {
				s.push(str[i]);
			}
			else if (str[i] == '[') {
				s.push(str[i]);
			}
			else
				continue;
		}
		if (!flag || s.size() > 0)
			cout << "no" << " " << '\n';
		else
			cout << "yes" << " " << '\n';
	}
	return 0;
}