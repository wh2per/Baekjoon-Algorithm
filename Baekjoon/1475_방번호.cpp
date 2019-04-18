#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int bj_1475() {
	string n;
	cin >> n;
	vector<int> v(9);

	for (int i = 0; i < n.size(); ++i) {
		if (n[i] - '0' == 6 || n[i] - '0' == 9)
			++v[6];
		else
			++v[n[i]-'0'];
	}
	
	int temp = INT_MIN;
	for (int i = 0; i < v.size(); ++i) {
		if (temp < v[i] && i!=6)
			temp = v[i];
	}

	if (temp > (v[6]+1) / 2)
		cout << temp;
	else
		cout << (v[6] + 1) / 2;

	return 0;
}