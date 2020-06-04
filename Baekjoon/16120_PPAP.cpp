#include <iostream> 
#include <string> 
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int p = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P') {
			p++;
			continue;
		}

		if (p >= 2 && s[i + 1] == 'P') {
			// PPAP는 P로 치환
			p--;
			// 뒤에 P까지 확인했으므로 i++ 
			i++;
		}
		else {
			cout << "NP\n";
			return 0;
		}
	}

	// P로 끝나야 PPAP 
	if (p == 1)
		cout << "PPAP\n";
	else
		cout << "NP\n";

	return 0;
}