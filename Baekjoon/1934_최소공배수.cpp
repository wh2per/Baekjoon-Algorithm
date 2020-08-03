#include <iostream>
using namespace std;

int gcd(int a, int b) {

	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int t; 
	cin >> t;
	int n1, n2;

	while (t--) {
		cin >> n1 >> n2;
		int gc = gcd(n1, n2);
		int ans = gc * (n1 / gc) * (n2 / gc);
		cout << ans << '\n';
	}
	return 0;
}