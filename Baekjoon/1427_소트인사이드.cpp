#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bj_1427() {
	string str;
	cin >> str;
	vector<char> v;

	for (auto a : str)
		v.push_back(a);
	sort(v.begin(), v.end());

	for (int i = v.size()-1; i >= 0; --i)
		cout << v[i];
	return 0;
}