#include <iostream>
#include <deque>
using namespace std;

int bj_1021() {
	deque<int> dq;
	int cnt = 0;

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		dq.push_back(i);
	int m;
	cin >> m;
	int size = n;
	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		
		if (dq.front() == t) {
			dq.pop_front();
			continue;
		}
		else {
			deque<int> tq1 = dq;
			int rc = 0;
			// 오른쪽으로 갈지 
			while (tq1.front() != t) {
				++rc;
				int temp = tq1.front();
				tq1.pop_front();
				tq1.push_back(temp);
			}

			deque<int> tq2 = dq;
			int lc = 0;
			// 왼쪽으로 갈지 
			while (tq2.front() != t) {
				++lc;
				int temp = tq2.back();
				tq2.pop_back();
				tq2.push_front(temp);
			}

			if (rc > lc) {
				dq = tq2;
				cnt += lc;
			}
			else {
				dq = tq1;
				cnt += rc;
			}
			dq.pop_front();

		}
	}

	cout << cnt;
	return 0;
}