#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	string a, b, c, d;
	cin >> a >> b >> c >> d;

	long long ia = stoi(a);
	ia *= pow(10, b.length());
	ia += stoi(b);

	long long ic = stoi(c);
	ic *= pow(10, d.length());
	ic += stoi(d);

	cout << ia + ic;

	return 0;
}