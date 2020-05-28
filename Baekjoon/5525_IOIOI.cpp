#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (s[i + 1] == 'O' && s[i + 2] == 'I') {
			int cnt = 0;
			while (s[i] == 'I' && s[i + 1] == 'O') {
				i += 2;
				++cnt;
				if (s[i] == 'I' && cnt == n) {
					--cnt;
					++ans;
				}
			}
		}
	}

	cout << ans;
	return 0;
}