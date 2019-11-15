#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int q;
	cin >> q;

	int ans = 0;
	for (int i = 0; i < 5; ++i) {
		int n;
		cin >> n;

		if (n == q)
			++ans;
	}
	cout << ans;
	return 0;
}