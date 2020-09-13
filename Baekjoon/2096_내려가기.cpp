#include <iostream>
using namespace std;

int t1[3];
int t2[3];

int main() {
	int n;
	cin >> n;

	for (int j = 0; j < 3; ++j) {
		int num;
		cin >> num;
		t1[j] = t2[j] = num;
	}

	for (int i = 2; i <= n; ++i) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		int temp1, temp2, temp3;

		temp1 = n1 + max(t1[0], t1[1]);
		temp2 = n2 + max(t1[0], max(t1[1], t1[2]));
		temp3 = n3 + max(t1[1], t1[2]);

		t1[0] = temp1;
		t1[1] = temp2;
		t1[2] = temp3;

		temp1 = n1 + min(t2[0], t2[1]);
		temp2 = n2 + min(t2[0], min(t2[1], t2[2]));
		temp3 = n3 + min(t2[1], t2[2]);

		t2[0] = temp1;
		t2[1] = temp2;
		t2[2] = temp3;
	}

	cout << max(t1[0], max(t1[1], t1[2])) << " " << min(t2[0], min(t2[1], t2[2]));

	return 0;
}