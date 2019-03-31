#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int bj_14888() {
	int min = INT_MAX;
	int max = INT_MIN;
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> oper(4);
	vector<char> q;
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	for (int i = 0; i < 4; ++i) {			// 0 : +,  1 : -, 2 : * , 3 : /
		int j;
		cin >> j;
		for (int k = 0; k < j; ++k)
			q.push_back(i);
	}

	do {
		int temp = v[0];
		for (int i = 0; i < q.size(); ++i) {
			if (q[i] == 0) {		// +
				temp += v[i + 1];
			}
			else if (q[i] == 1) {		// -
				temp -= v[i + 1];
			}
			else if (q[i] == 2) {		// *
				temp *= v[i + 1];
			}
			else {				//  /
				temp /= v[i + 1];
			}
		}
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
	} while (next_permutation(q.begin(), q.end()));

	cout << max << '\n' << min;
	return 0;
}