#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("n.txt", "r", stdin);

	int maxNum=0, n, ni;
	for (int i = 0; i < 81; i++) { 
		cin >> n; 
		if (maxNum <= n) { 
			maxNum = n; 
			ni = i; 
		} 
	} 
	cout << maxNum << '\n'; 
	cout << ni / 9 + 1 << ' ' << ni % 9 + 1;


	return 0;
}