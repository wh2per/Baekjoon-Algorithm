#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

// 세점의 ccw를 구하면 면적이됨
double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (-y1 * x2 - y2 * x3 - y3 * x1);
	return res / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<pair<double, double>> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;
	
	double ans=0;
	for (int i = 1; i < n; ++i)
		ans += ccw(arr[0].first, arr[i - 1].first, arr[i].first, arr[0].second, arr[i - 1].second, arr[i].second);
	
	cout << fixed;
	cout.precision(1);
	cout << abs(ans);

	return 0;
}