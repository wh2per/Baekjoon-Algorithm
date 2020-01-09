#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int t;
	cin >> t;
	while (t--) {
		int hp, mp, attack, defense, h, m, a, d;
		cin >> hp >> mp >> attack >> defense >> h >> m >> a >> d;

		hp = max(1, hp + h);
		mp = max(1, mp + m);
		attack = max(0, attack + a);
		defense += d;

		cout << hp + 5 * mp + 2 * attack + 2 * defense << "\n";
	}

	return 0;
}