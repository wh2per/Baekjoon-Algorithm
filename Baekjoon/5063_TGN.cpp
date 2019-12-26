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

	int n, r, e, c, i;

	cin >> n;
	while (n--) {
		cin >> r >> e >> c;

		if ((r + c) < e)
			cout << "advertise\n";
		else if ((r + c) > e)
			cout << "do not advertise\n";
		else if ((r + c) == e)
			cout << "does not matter\n";
	}

	return 0;
}