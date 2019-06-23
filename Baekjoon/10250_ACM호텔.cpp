#include <iostream>
#include <string>
using namespace std;

int bj_10250() {
	int t;
	cin >> t;
	while (t--) {
		int h, w, num;
		string ans = "";
		cin >> h >> w >> num;
		
		int a = (num / h)+1;
		int b = num % h;
		if (b == 0) {
			b = h;
			--a;
		}

		ans += to_string(b);
		if (a < 10)
			ans += "0";
		ans += to_string(a);
		cout << ans << '\n';
	}
	return 0;
}