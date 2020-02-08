#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	string s,n;
	getline(cin, s);

	stringstream ss;
	ss.str(s);

	int num = 0;
	
	while (ss >> n) 
		num += atoi(n.c_str());

	cout << num;

	return 0;
}