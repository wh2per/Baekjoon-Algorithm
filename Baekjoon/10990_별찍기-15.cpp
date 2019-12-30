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

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n - i; ++j)
			cout << " ";
		cout << "*";
		if (i == 0) {
			cout << "\n";
			continue;
		}
		for (int j = 0; j < 2*i-1; ++j)
			cout << " ";
		cout << "*\n";
	} 

	return 0;
}