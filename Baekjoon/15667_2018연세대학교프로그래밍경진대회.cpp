#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, a = 0, b;

	cin >> n;
	n -= 1;

	while (true) {
		a++;
		if (a * a + a == n)
			break;
	}
	cout << a;
	return 0;
}