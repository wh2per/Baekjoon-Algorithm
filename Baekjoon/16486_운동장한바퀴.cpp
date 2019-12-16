#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	double a, b;
	cin >> a >> b;

	printf("%.6f", a * 2 + 2 * b * 3.141592);
	return 0;
}