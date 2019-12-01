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

	int t;
	cin >> t;

	int a, b, c;
	int ans = 0;
	a = t / 300;
	t %= 300;

	b = t / 60;
	t %= 60;

	c = t / 10;
	t %= 10;

	if (t != 0)
		cout << -1;
	else
		cout << a << " "<<b<<" "<<c;
	return 0; 
}