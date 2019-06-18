#include <iostream>
#include <string>
using namespace std;

string fibo_add(string ans1, string ans2) {
	bool flag = false;
	int e1 = ans1.length();
	int e2 = ans2.length();

	for (int i = 1; i <= ans1.length(); ++i) {
		int a = ans1[e1 - i] - '0';
		int b = ans2[e2 - i] - '0';
		if (flag) {
			++a;
			flag = false;
		}
		b += a;
		if (b > 9) {
			b -= 10;
			flag = true;
		}
		ans2[e2 - i] = b+'0';
	}
	
	if (flag) {
		if (e1 == e2) {
			ans2 = "1" + ans2;
		}
		else {
			int a = ans2[0] - '0';
			++a;
			if (a > 9) {
				a -= 10;
				ans2[0] = a + '0';
				ans2 = "1" + ans2;
			}
			else {
				ans2[0] = a + '0';
			}
		}
	}
	return ans2;
}

int bj_10826() {
	string ans1 = "0", ans2 = "1", temp; 
	int n;
	cin >> n;
	if (n == 0)
		cout << 0;
	else {
		for (int i = 1; i < n; ++i) {
			temp = ans2;
			ans2 = fibo_add(ans1, ans2);
			ans1 = temp;
		}
		cout << ans2;
	}
	return 0;
}