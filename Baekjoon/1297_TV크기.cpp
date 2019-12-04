#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int a, b, c;
	cin >> a >> b >> c;

	float x = a / sqrt(b * b + c * c);

	cout << (int)(b*x) <<" "<<(int)(c*x);

	return 0;
}