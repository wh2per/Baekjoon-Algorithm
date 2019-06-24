#include <iostream>
using namespace std;

int bj_2884() {
	int a, b;
	cin >> a >> b;
	int time = a * 60 + b;
	if (time < 45)
		time += 1440;
	time -= 45;
	
	if (time / 60 != 0)
		cout << time / 60 << " "; 
	if(time%60!=0)
		cout <<time % 60;
	return 0;
}