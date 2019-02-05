#include <iostream>
#include <vector>
#include <string>
using namespace std;

int bj_1924() {
	vector<int> dates = {31,28,31,30,31,30,31,31,30,31,30,31};
	vector<string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int x, y;
	cin >> x >> y;
	int count=0;
	for (int i = 1; i < x; i++)
		count += dates[i - 1];
	count += y;
	cout << day[count % 7];

	return 0;
}