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
		int candy, sibling;
		cin >> candy >> sibling;

		cout << "You get "<<candy/sibling<<" piece(s) and your dad gets "<<candy % sibling<<" piece(s).\n";
	}

	return 0;
}