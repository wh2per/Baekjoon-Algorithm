#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		for (int i = 0; i < a; i++){
			for (int j = 0; j < a; j++){
				if (i != 0 && i != a - 1 && j != 0 && j != a - 1)
					cout << "J";
				else
					cout << "#";
			}
			if (n != 0 || i!=a-1)
				cout << endl;
		}
		if (n != 0)
			cout << endl;
	}

	return 0;
}