#include <iostream>
#include <vector>
using namespace std;

int bj_1003() {
	int T;
	cin >> T;

	vector<vector<int>> arr(41, vector<int>(2, 0));
	arr[0][0] = 1;
	arr[0][1] = 0;

	arr[1][0] = 0;
	arr[1][1] = 1;

	for (int i = 0; i < T; ++i) {
		int num;
		cin >> num;
		
		for (int j = 2; j <= num; ++j) {
			arr[j][0] = arr[j - 1][0] + arr[j - 2][0];
			arr[j][1] = arr[j - 1][1] + arr[j - 2][1];
		}
		cout << arr[num][0] << " " << arr[num][1] << '\n';
	}
	return 0;
}