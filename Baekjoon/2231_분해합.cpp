#include <iostream>
using namespace std;

int split_sum(int num) {
	int ans = num;
	int split = num;
	while (split != 0) {
		ans += split % 10;
		split /= 10;
	}
	return ans;
}

int bj_2231() {
	int num;
	cin >> num;
	int temp = num;
	int count = 0;
	while (temp != 0) {
		temp /= 10;
		++count;
	}
	if (count > 0)
		--count;
	int start = num - (9 * count);
	
	int i = start;
	for (i = start; i <= num; ++i) {
		int ans = split_sum(i);
		
		if (ans == num) {
			cout << i;
			break;
		}
	}
	if (i > num)
		cout << 0;

	return 0;
}