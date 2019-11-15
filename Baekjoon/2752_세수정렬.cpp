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

	freopen("input.txt", "r", stdin);

	vector<int> a(3);

	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (auto d : a)
		cout << d << " ";
	return 0;
}