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

	long long A, B;
	cin >> A >> B;

	if (A > B)
		swap(A, B);

	cout << (A + B) * (B - A + 1) / 2 << "\n";

	return 0;
}