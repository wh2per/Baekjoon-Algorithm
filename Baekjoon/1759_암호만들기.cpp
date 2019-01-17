#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int bj_1759() {
	int l;
	int c;

	cin >> l;
	cin >> c;

	vector<char> arr(c);
	vector<char> ans(l);
	vector<int> d(c);
	int m = 0, j = 0, index = 0;

	for (int i = 0; i < l; i++)
		d[i] = -1;

	for (int i = 0; i < c; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	do {
		m = 0;
		j = 0;
		index = 0;
		for (int i = 0; i < c; i++) {
			if (d[i] == -1) {
				ans[index++] = arr[i];
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
					m++;
				else
					j++;
			}
		}
		if (m > 0 && j > 1) {
			for (int i = 0; i < l; i++)
				cout << ans[i];
			cout << endl;
		}

	} while (next_permutation(d.begin(), d.end()));


	//system("pause");
	return 0;
}