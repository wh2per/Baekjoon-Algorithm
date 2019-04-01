#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bj_7662() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int k;
		cin >> k;

		priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;		// pair에서 first기준으로 정렬
		vector<bool> check(k,false);
		int idx = 0;
		for (int j = 0; j < k; ++j) {
			char op;
			int num;
			cin >> op >> num;

			if (op == 'I') {		// 삽입
				maxHeap.push({num,idx});
				minHeap.push({num,idx++});
			}
			else {				// 삭제
				if (num==1) {			// 최댓값 삭제
					while (!maxHeap.empty() && check[maxHeap.top().second])
						maxHeap.pop();

					if (!maxHeap.empty()) {
						check[maxHeap.top().second] = true;
						maxHeap.pop();
					}
				}
				else {						// 최솟값 삭제
					while (!minHeap.empty() && check[minHeap.top().second])
						minHeap.pop();

					if (!minHeap.empty()) {
						check[minHeap.top().second] = true;
						minHeap.pop();
					}
				}
			}
		}
		while (!maxHeap.empty() && check[maxHeap.top().second])
			maxHeap.pop();
		while (!minHeap.empty() && check[minHeap.top().second])
			minHeap.pop();

		if (minHeap.empty() && maxHeap.empty())
			cout << "EMPTY\n";
		else
			cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
	}
	return 0;
}