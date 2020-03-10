#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int time = a * 60 + b;
	if (time < 45)
		time += 1440;
	time -= 45;
	
	cout << time / 60 << " "<< time % 60;
	return 0;
}