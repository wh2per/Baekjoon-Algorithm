#include <iostream>
#include <stdio.h>

using namespace std;

int bj_1110(void) {
	int ref, num, cycle = 0;
	cin >> num;
	ref = num;

	while (true) {
		if (num < 10) {
			num = num * 10 + num;
		}
		else {
			num = (num % 10) * 10 + (num % 10 + num / 10) % 10;
		}
		cycle++;

		if (num == ref)
			break;
	}

	cout << cycle << endl;
	return 0;
}


