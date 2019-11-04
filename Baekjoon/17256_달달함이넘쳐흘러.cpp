#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int ax, ay, az, cx, cy, cz;
	cin >> ax >> ay >> az >> cx >> cy >> cz;

	cout << cx - az << " " << cy / ay << " " << cz - ax;
	return 0;
}