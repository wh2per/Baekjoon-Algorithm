#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bj_2858() {
	int B, R;
	cin >> R >> B;

	vector<pair<int, int>> v;
	// 약수 검사
	for (int i = 1; i*i <= B; ++i) {
		if (B%i == 0) {		// 약수일때
			v.push_back({i,B/i});
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		int col = v[i].first;
		int row = v[i].second;
		if ((col * 2) + (row + 2) * 2 == R) {
			cout << row+2  << " " << col+2;
			return 0;
		}
	}

	return 0;
}