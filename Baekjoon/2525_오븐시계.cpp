#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int hour, min;
	cin >> hour >> min;

	int num;
	cin >> num;

	int over = (min + num) / 60;
	min = (min + num) % 60;
	
	if (over > 0) {
		hour += over;
		if (hour > 23)
			hour -= 24;
	}

	cout << hour << " " << min;
	return 0;
}