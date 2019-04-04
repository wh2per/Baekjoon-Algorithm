#include <iostream>
using namespace std;

int bj_1676(){
	int n;
	cin >> n;
	int count = n/5;
	int count2 = n/25;
	int count3 = n/125;
	cout << count+count2+count3;
	return 0;
}