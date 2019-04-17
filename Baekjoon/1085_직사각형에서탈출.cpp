#include <iostream>
#include <algorithm>

using namespace std;

int bj_1085() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << min(min(w-x,h-y),min(x,y));
	return 0;
}