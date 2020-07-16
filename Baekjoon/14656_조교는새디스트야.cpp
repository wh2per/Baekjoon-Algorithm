#include <iostream>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp != i) 
			cnt++;
	}
	cout << cnt;

	return 0;
}