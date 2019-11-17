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

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	vector<int> b(n, 1);
	for (int i = 0; i < n; ++i)
		v[i] = i + 1;
	for (int i = 0; i < m; ++i)
		b[i] = 0;

	do {
		for (int i = 0; i < n; ++i) {
			if (b[i] == 0)
				cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(b.begin(), b.end()));

	return 0;
}