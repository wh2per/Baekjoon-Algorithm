#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

bool check[21];
long long d[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	d[0] = 1;
	for (int i = 1; i < 21; ++i)
		d[i] = i * d[i - 1];

	int k;
	cin >> k;

	if (k == 1) {
		long long num;
		cin >> num;

		vector<int> arr(n);

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (check[j])
					continue;
				if (num > d[n - i - 1])
					num -= d[n - i - 1];
				else {
					arr[i] = j;
					check[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
	}else {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		long long num = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < arr[i]; ++j) {
				if (check[j])
					continue;
				num += d[n - 1 - i];
			}
			check[arr[i]] = true;
		}
		cout << num + 1;
	}
	
	return 0;
}