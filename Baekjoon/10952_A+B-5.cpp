#include <iostream>
using namespace std;

int bj_10952() {
	while(1){
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		cout << a + b << endl;
	} 

	return 0;
}