#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	vector<int> b(3);
	vector<int> d(2);

	for (int i = 0; i < 3; ++i)
		cin >> b[i];

	for (int i = 0; i < 2; ++i)
		cin >> d[i];

	sort(b.begin(), b.end());
	sort(d.begin(), d.end());

	cout << b[0] + d[0]-50;
	return 0;
}