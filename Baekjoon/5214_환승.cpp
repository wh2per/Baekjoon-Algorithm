#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> info;
vector<int> check;

queue<int> qs;
queue<int> qe;

long long scnt;
long long ecnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> k >> m;

	info.assign(n + m + 1, vector<int>());
	check.assign(n + m + 1, 0);


	for (int i = n + 1; i < m + n + 1; ++i) {
		for (int j = 0; j < k; ++j) {
			int num;
			cin >> num;
			info[i].push_back(num);
			info[num].push_back(i);
		}
	}

	if (n == 1) {
		cout << 1;
		return 0;
	}

	qs.push(1);
	qe.push(n);
	check[1] = 1;
	check[n] = 2;
	scnt = 1;
	ecnt = 1;

	while (!qs.empty() && !qe.empty()) {
		int ssize = qs.size();
		int esize = qe.size();

		for (int i = 0; i < ssize; ++i) {
			int pos = qs.front();
			qs.pop();

			for (auto a : info[pos]) {
				if (check[a] == 0) {
					check[a] = 1;
					qs.push(a);
				}
				else if (check[a] == 2) {
					if ((scnt + ecnt) % 2)
						cout << (scnt + ecnt + 1) / 2;
					else
						cout << (scnt + ecnt) / 2;
					return 0;
				}
			}
		}
		if (ssize != 0)
			++scnt;

		for (int i = 0; i < esize; ++i) {
			int pos = qe.front();
			qe.pop();

			for (auto a : info[pos]) {
				if (check[a] == 0) {
					check[a] = 2;
					qe.push(a);
				}
				else if (check[a] == 1) {
					if ((scnt + ecnt) % 2)
						cout << (scnt + ecnt + 1) / 2;
					else
						cout << (scnt + ecnt) / 2;
					return 0;
				}
			}
		}
		if (esize != 0)
			++ecnt;
	}

	cout << -1;
	return 0;
}
