#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	vector<int> v(n);
	unordered_map<int, int> um;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	vector<int> copyV;
	copyV.assign(v.begin(), v.end());

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (um.count(v[i]) == 0)
			um.insert({v[i],cnt++});
	}

	for (int i = 0; i < n; ++i) 
		cout << um[copyV[i]] << " ";

	return 0;
}