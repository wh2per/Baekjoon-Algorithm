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

	int t;
	cin >> t;


	while (t--) {
		int n, m;
		cin >> n >> m;

		cout << m * 2 - n << " " << (n - m) << "\n";
	}
	
	return 0;
}