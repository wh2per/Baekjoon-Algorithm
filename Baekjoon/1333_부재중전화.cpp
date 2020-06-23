#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	vector<int> music;

	int N, L, D;
	int bell = 0;

	cin >> N >> L >> D;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < L; ++j)
			music.push_back(1);
		for (int j = 0; j < 5; ++j)
			music.push_back(0);
	}

	while (1) {
		if (bell > music.size())
			break;
		if (music[bell] == 0)
			break;
		else
			bell += D;
	}

	cout << bell;
	return 0;
}