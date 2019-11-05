#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		cout << "0 0";
		return 0;
	}
	++k;
	int row = k / m;
	if (k % m == 0)
		--row;
	int col = k % m;
	if (col == 0)
		col = m - 1;
	else
		--col;

	cout << row << " " << col;
	return 0;
}