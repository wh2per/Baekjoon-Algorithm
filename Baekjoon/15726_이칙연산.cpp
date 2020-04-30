#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;

	int t1 = (double)a * b / c;
	int t2 = (double)a / b * c;

	if (t1 > t2)
		cout << t1;
	else
		cout << t2;

	return 0;
}