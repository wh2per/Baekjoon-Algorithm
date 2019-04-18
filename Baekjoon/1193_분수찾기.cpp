#include <iostream>
using namespace std;

int bj_1193() {
	int n;
	int count = 1;

	cin >> n;
	int temp = 1;
	while (temp < n) {
		temp = count*(count+1)/2;
		++count;
	}
	count -= 2;
	temp = count * (count + 1) / 2;
	
	if (temp != n)
		++count;

	if (count % 2 == 0) {
		cout << n-temp << "/" << count - n + temp + 1;
	}
	else {
		cout << count - n + temp +1 << "/" << n - temp;
	}
	
	return 0;
}