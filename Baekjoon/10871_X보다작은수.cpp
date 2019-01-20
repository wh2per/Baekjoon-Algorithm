#include <iostream>
#include <queue>
using namespace std;

int bj_10871() {
	int n, x;
	cin >> n >> x;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	for (int i = 0; i < n; i++) {
		int temp = q.front();
		q.pop();

		if (temp < x)
			cout << temp << " ";
	}


	return 0;
}