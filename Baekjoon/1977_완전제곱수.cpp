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

	int start, end;
	cin >> start >> end;

	int sum = 0, minNum = -1;
	bool flag = false;

	for (int i = 1; i < 101; ++i) {
		if (i * i >= start && i * i <= end) {
			sum += i * i;
			if (!flag) {
				minNum = i * i;
				flag = true;
			}
		}
	}
	if (sum != 0)
		cout << sum << endl;
	cout << minNum;

	return 0;
}