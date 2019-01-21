#include <iostream>

using namespace std;

int bj_11720(void) {
	int n;

	cin >> n;

	char *line = new char[n + 1];
	cin >> line;
	int sum = 0;
	int len = n;

	for (int i = 0; i < len; i++) {
		sum += line[i] - '0';
	}
	cout << sum;
	//system("pause");
	return 0;
}