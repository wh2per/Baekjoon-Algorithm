#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cout << "NFC West       W   L  T\n";
	cout << "-----------------------\n";
	cout << "Seattle        13  3  0\n";
	cout << "San Francisco  12  4  0\n";
	cout << "Arizona        10  6  0\n";
	cout << "St. Louis      7   9  0\n";
	cout << "\n";
	cout << "NFC North      W   L  T\n";
	cout << "-----------------------\n";
	cout << "Green Bay      8   7  1\n";
	cout << "Chicago        8   8  0\n";
	cout << "Detroit        7   9  0\n";
	cout << "Minnesota      5  10  1\n";
	return 0;
}