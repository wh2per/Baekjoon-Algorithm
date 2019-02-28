#include <iostream>
using namespace std;

const int inf = -100000000;
int n_14501;
int t_14501[20];
int p_14501[20];
int ans_14501 = 0;

void go(int day, int sum) {
	if (day == n_14501) {
		if (ans_14501 < sum) ans_14501 = sum;
		return;
	}

	if (day > n_14501)
		return;

	go(day + 1, sum);
	go(day + t_14501[day], sum + p_14501[day]);
}

int bj_14501() {

	cin >> n_14501;
	for (int i = 0; i < n_14501; i++)
		cin >> t_14501[i] >> p_14501[i];
	go(0, 0);
	cout << ans_14501 << '\n';
	//system("pause");
	return 0;
}