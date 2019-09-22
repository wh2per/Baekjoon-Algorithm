#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int find(int n) {
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

void merge(int a, int b) {
	int num1, num2;
	num1 = find(a);
	num2 = find(b);
	if (num1 == num2)
		return;
	v[num2] = num1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;
	
	v.assign(n + 1,0);

	for (int i = 1; i <= n; ++i)
		v[i] = i;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int num;
			cin >> num;
			if (num == 1) 
				merge(i, j);
		}
	}
	int start;
	cin >> start;
	bool flag = true;
	for (int i = 1; i < m; ++i) {
		int end;
		cin >> end;
		if (find(start) != find(end)) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}