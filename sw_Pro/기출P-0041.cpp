#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cout << "#" << t << " ";
		int n = 131072 * 2;
		int size = 1;
		while (size < n)
			size <<= 1;
		size *= 2;
		int start = size - n - 1;
		vector <int> v1(size, 0);
		for (int i = size - n; i < size; ++i) {
			int num;
			cin >> num;
			v1[i] = num;
		}

		int p = (size - 1) / 2;				// 구간합 구하기
		for (int i = p; i > 0; --i) {
			v1[i] = min(v1[i * 2], v1[i * 2 + 1]);
		}



		int Q;
		cin >> Q;
		for (int i = 0; i < Q; ++i) {
			int be, x;
			cin >> be >> x;
			if (be == 1) {			// 참가자가 카드를 뽑는다.
				score.insert(x);
			}
			else {				// 진행자가 카드를 뽑는다.
				set<int>::iterator iter = score.begin();
				for(int j=0; j<x-1; ++j)
					++iter;
				cout << *iter << " ";
				score.erase(iter);
			}
		}
		cout << "\n";
	}

	return 0;
}