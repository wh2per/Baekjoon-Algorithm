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
	
	for (int i = 0; i < 9; ++i) {
		int a;
		cin >> a;
		n -= a;
	}
	cout << n;
	return 0;
}