#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	map<string, bool> db;

	while (n--) {
		string s;
		cin >> s;

		db.insert({ s, false });
	}

	int cnt = 0;

	while (m--) {
		string s;
		cin >> s;

		if (db.count(s) > 0) {
			db[s] = true;
			++cnt;
		}
	}

	cout << cnt << "\n";
	for (auto it = db.begin(); it != db.end(); it++) {
		if (it->second)
			cout << it->first << '\n';
	}

	return 0;
}