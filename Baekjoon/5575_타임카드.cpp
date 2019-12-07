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

	freopen("input.txt", "r", stdin);

	int h1, h2, m1, m2, s1, s2;
	int h, m, s;

	for (int i = 0; i < 3; i++) {
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		if ((s2 - s1) >= 0)
			s = s2 - s1;
		else {
			s = s2 - s1 + 60;
			m2--;
		}
		if ((m2 - m1) >= 0)
			m = m2 - m1;
		else {
			m = m2 - m1 + 60;
			h2--;
		}

		h = h2 - h1;
		cout << h << " " << m << " " << s << "\n";
	}

	return 0;
}