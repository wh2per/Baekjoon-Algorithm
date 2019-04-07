#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_2309() {
	vector<int> arr(9);
	vector<int> select(9, 0);
	for (int i = 0; i < 9; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	select[8] = 1;
	select[7] = 1;

	do {
		int result = 0;
		for (int i = 0; i < 9; ++i) {
			if (select[i] == 0)
				result += arr[i];
		}

		if (result == 100)
			break;
	} while (next_permutation(arr.begin(), arr.end()));

	for (int i = 0; i < 9; ++i) {
		if (select[i] == 0)
			cout << arr[i] << '\n';
	}
	return 0;
}
