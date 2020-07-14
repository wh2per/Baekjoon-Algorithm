#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	vector<int> a(10, 0);
	vector<int> b(10, 0);

	for (int i = 0; i < 10; ++i)
		cin >> a[i];
	for (int i = 0; i < 10; ++i)
		cin >> b[i];

	int asum = 0, bsum = 0;
	string win = "";


	for (int i = 0; i < 10; ++i) {
		if (a[i] > b[i]) {
			asum += 3;
			win = "A";
		}
		else if (a[i] < b[i]) {
			bsum += 3;
			win = "B";
		}
		else {
			asum += 1;
			bsum += 1;
		}
	}

	if (asum == 10 && bsum == 10)
		win = "D";

	if (asum > bsum)
		cout << asum << " " << bsum << " A";
	else if(asum < bsum)
		cout << asum << " " << bsum << " B";
	else {
		if(win == "A")
			cout << asum << " " << bsum << " A";
		else if(win=="B")
			cout << asum << " " << bsum << " B";
		else
			cout << asum << " " << bsum << " D";
	}

	return 0;
}