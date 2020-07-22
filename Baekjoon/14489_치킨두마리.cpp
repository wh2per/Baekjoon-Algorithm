#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int a, b, c;
	cin >> a >> b >> c;
	
	long long temp = a + b;

	if (temp >= c*2) {
        cout << temp - c*2 << "\n";
    } else {
        cout << temp << "\n";
    }

	return 0;
}