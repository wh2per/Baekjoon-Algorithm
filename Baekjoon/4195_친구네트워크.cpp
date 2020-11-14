#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> v;
vector<int> number;

int find(int n) {
	if (v[n] == n)
		return n;
	return v[n] = find(v[n]);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		v[b] = a;
		number[a] += number[b];
		number[b] = 1;
	}
	return number[a];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int f;
		cin >> f;

		v.assign(200001, 0);
		number.assign(200001, 0);
		map<string, int> info;
		for (int i = 1; i <= 200000; ++i) {
			v[i] = i;
			number[i] = 1;
		}

		int cnt = 1;
		for (int i = 0; i < f; ++i) {
			string a, b;
			cin >> a >> b;

			int num1, num2;
			if (info.count(a) == 0)
				info[a] = cnt++;
			if (info.count(b) == 0)
				info[b] = cnt++;

			cout << merge(info[a], info[b]) << "\n";
		}
	}

	return 0;
}