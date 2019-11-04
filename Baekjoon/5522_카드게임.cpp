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

	int sum = 0;
	int a = 5;
	while (a--) {
		int n;
		cin >> n;
		sum += n;
	}

	cout << sum;

	return 0;
}