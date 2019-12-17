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

	int a, b, c;
	cin >> a >> b >> c;

	long long t1 = a / c;
	if (a % c != 0)
		++t1;
	long long t2 = b / c;
	if (b % c != 0)
		++t2;
	cout << t1 * t2;

	return 0;
}