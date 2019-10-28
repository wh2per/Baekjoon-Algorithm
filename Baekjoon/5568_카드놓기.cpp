#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

vector<string> v;
vector<int> check;
set<string> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	v.assign(n, "");
	check.assign(n, 1);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < k; ++i)
		check[i] = 0;

	do {
		vector<string> v2;
		vector<int> check2(k);

		for (int i = 0; i < n; ++i) {
			if (check[i] == 0)
				v2.push_back(v[i]);
		}

		for (int i = 0; i < k; ++i)
			check2[i] = i;
		do {
			string temp = "";
			for (auto a : check2)
				temp += v2[a];
			s.insert(temp);
		} while (next_permutation(check2.begin(), check2.end()));
	} while (next_permutation(check.begin(), check.end()));

	cout << s.size();
	return 0;
}