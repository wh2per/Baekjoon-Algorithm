#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < n - i-1; ++j)
			cout << " ";
		cout << "*";
		for (int j = 0; j < i * 2 - 1; ++j)
			cout << " ";
		if(i!=0)
			cout << "*";
		cout << endl;
	}
	
	for (int i = 0; i < n * 2 - 1; ++i)
		cout << "*";

	return 0;
}