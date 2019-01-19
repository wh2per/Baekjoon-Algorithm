#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> lotto;

void go(vector<int> &a, int index, int cnt) {
	if (cnt == 6) {
		for (int num : lotto) {
			printf("%d ", num);
		}
		printf("\n");
		return;
	}
	int n = a.size();
	if (n == index) return;
	lotto.push_back(a[index]);
	go(a, index + 1, cnt + 1);
	lotto.pop_back();
	go(a, index + 1, cnt);
}

int bj_6603() {
	int n;

	while (true) {
		cin >> n;
		if (n == 0)
			break;
		vector<int> a(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];

		go(a, 0, 0);
		cout << '\n';
	}
}