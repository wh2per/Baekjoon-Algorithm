#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	string s;
	cin >> s;

	string ts = "";
	
	for (int i = 0; i < s.size(); i++){
		ts = s; 
		s = ((ts[0]) - '0' * ts.size()) + '0';
	}

	if (s.size() == 1)
		cout << "FA";
	else
		cout << "NFA";
	return 0;
}