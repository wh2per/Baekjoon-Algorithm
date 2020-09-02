#include <iostream> 
#include <string> 
using namespace std;

int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int arr[6] = { 0, 1, 2, 6, 24, 120 };
	while (1) {
		string s;
		int len, sum = 0;
		cin >> s;

		if (s == "0")
			break;
		len = s.length();

		for (int i = 0; i < len; i++)
			sum += arr[len - i] * (s[i] - '0');
		cout << sum << '\n';
	}

	return 0;
}

