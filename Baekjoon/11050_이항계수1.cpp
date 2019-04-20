#include <iostream>
using namespace std;

int bj_11050(){
	int n, k;
	cin >> n >> k;

	int first = 1;
	for (int i = 0; i < n; ++i)
		first *= (i + 1);
	int second = 1;
	for (int i = 0; i < k; ++i)
		second *= (i + 1);
	int temp = n - k;
	int third = 1;
	for (int i = 0; i < temp; ++i)
		third *= (i + 1);
	cout << first / second / third;
	return 0;
}