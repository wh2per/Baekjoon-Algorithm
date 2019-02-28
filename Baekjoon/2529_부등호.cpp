#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n_2529;
char a_2529[20];
vector<string> ans_2529;
bool check_2529[10];

bool good(char x, char y, char op) {
	if (op == '<') {
		if (x > y) return false;
	}
	if (op == '>') {
		if (x < y) return false;
	}
	return true;
}
void go(int index, string num) {
	if (index == n_2529 + 1) {
		ans_2529.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (check_2529[i]) continue;
		if (index == 0 || good(num[index - 1], i + '0', a_2529[index - 1])) {
			check_2529[i] = true;
			go(index + 1, num + to_string(i));
			check_2529[i] = false;
		}
	}
}
int bj_2529() {
	cin >> n_2529;
	for (int i = 0; i < n_2529; i++) {
		cin >> a_2529[i];
	}
	go(0, "");
	auto p = minmax_element(ans_2529.begin(), ans_2529.end());
	cout << *p.second << '\n';
	cout << *p.first << '\n';

	//system("pause");
	return 0;
}