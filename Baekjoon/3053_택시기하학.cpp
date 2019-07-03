#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

int bj_3053(){
	int x;
	cin >> x;

	cout << fixed;
	cout.precision(6);

	cout << x * x*M_PI << endl;
	cout << x * x * 2.0 << endl;	

	return 0;
}
