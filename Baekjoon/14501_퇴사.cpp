#include <iostream>
using namespace std;

const int inf = -100000000;
int n;
int t[20];
int p[20];
int ans = 0;

void go(int day, int sum) {
	if (day == n) {
		if (ans < sum) ans = sum;
		return;
	}

	if (day > n)
		return;

	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
}

int bj_14501() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
	go(0, 0);
	cout << ans << '\n';
	//system("pause");
	return 0;
}