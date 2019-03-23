#include <iostream>
#include <string>
using namespace std;

int bj_1436() {
	int N;
	cin >> N;
	
	int ans = 0;
	int count = 0;

	for (int i = 666; ; i++) {
		string s = to_string(i);
		if (s.find("666") != -1)	// 못찾았으면
			count++;
		if (count == N) {
			cout << i;
			break;
		}
	}
	return 0;
}