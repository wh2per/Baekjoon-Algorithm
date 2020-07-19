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

	string w;
	int a[3] = { 1,0,0 };
	cin >> w;

	for (int i = 0; i < w.size(); i++)
	{
		switch (w[i])
		{
		case 'A':
			swap(a[0], a[1]);
			break;
		case 'B':
			swap(a[1], a[2]);
			break;
		case 'C':
			swap(a[0], a[2]);
			break;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (a[i] == 1) {
			cout << i + 1 << '\n'; 
			break;
		}
	}

	return 0;
}