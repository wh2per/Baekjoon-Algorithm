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

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		if (m==1)
			++ans;
	}

	if (n / 2 < ans)
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";

	return 0;
}