#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	vector<int> v(4);
	for (int i = 0; i < 4; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	cout << abs(v[0] + v[3] - v[1] - v[2]);

	return 0;
}