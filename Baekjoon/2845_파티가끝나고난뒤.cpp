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

	freopen("input.txt", "r", stdin);

	int l, p;
	cin >> l >> p;

	p *= l;
	for (int i = 0; i < 5; ++i) {
		int n;
		cin >> n;
		cout << n-p<<" ";
	}



	return 0;
}