#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bj_2751() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end(),less<int>());

	for (auto i : v)
		cout << i << '\n';
	return 0;
}