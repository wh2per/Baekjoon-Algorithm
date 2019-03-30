#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int bj_10546() {
	int N;
	cin >> N;
	map<string, int> m;
	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;
		if (m.count(name) == 0)
			m.insert({ name,1 });
		else
			m[name]++;
	}

	for (int i = 0; i < N - 1; ++i) {
		string name;
		cin >> name;
		if (m[name] == 1)
			m.erase(name);
		else
			m[name]--;
	}

	cout << (m.begin())->first;
	return 0;
}