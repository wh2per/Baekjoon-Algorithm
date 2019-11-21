#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if (n == 0)
		cout << "YONSEI";
	else
		cout << "Leading the Way to the Future";

	return 0;
}