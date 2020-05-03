#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double a, b, c, d;
	cin >> a >> b >> c >> d;

	double ans1 = a / c + b / d;
	double ans2 = c / d + a / b;
	double ans3 = d / b + c / a;
	double ans4 = b / a + d / c;
	double ans = max(ans1, max(ans2, max(ans3, ans4)));

	if (ans1 == ans)
		cout << 0;
	else if (ans2 == ans)
		cout << 1;
	else if (ans3 == ans)
		cout << 2;
	else
		cout << 3;

	return 0;
}