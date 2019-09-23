#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int find(int n) {
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

void merge(int a, int b) {
	int num1, num2;
	num1 = find(a);
	num2 = find(b);
	if (num1 == num2)
		return;
	v[num1] = num2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g, p;
	cin >> g >> p;

	v.assign(g + 1, 0);
	for (int i = 1; i <= g; ++i)			// vÃÊ±âÈ­
		v[i] = i;

	int ans = 0;
	for (int i = 0; i < p; ++i) {
		int num;
		cin >> num;

		int docking = find(num);
		if (docking != 0) {
			merge(docking, docking - 1);
			++ans;
		}
		else
			break;
	}
	cout << ans;

	return 0;
}