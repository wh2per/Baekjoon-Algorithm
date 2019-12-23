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

	//freopen("input.txt", "r", stdin);

	char a[10];
	cin.getline(a, 10);
	if ((a[0] - '0') + (a[4] - '0') == (a[8] - '0'))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}