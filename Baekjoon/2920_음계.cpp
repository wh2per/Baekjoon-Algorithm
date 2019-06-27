#include <iostream>
#include <vector>
using namespace std;

int bj_2920() {
	vector<int> v(8,0);
	for (int i = 0; i < 8; ++i)
		cin >> v[i];

	int j = 0;
	int prev = v[0];
	int count = 0;
	for (j = 1; j < 8; ++j) {
		if (prev < v[j])
			++count;
		else
			--count;
		prev = v[j];
	}

	if (count == 7)
		cout << "ascending";
	else if (count == -7)
		cout << "descending";
	else
		cout << "mixed";
	return 0;
}