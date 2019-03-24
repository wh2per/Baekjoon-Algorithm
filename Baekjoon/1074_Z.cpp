#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int ans_square;

void re_square(int y, int x, int N, int xstart, int xend, int ystart, int yend) {
	int size = pow(2, N);

	if (N == 0) {
		cout << ans_square;
		return;
	}
	// 구역 탐색 0,1,2,3
	int xflag = 0, yflag = 0;
	int strict = 0;
	if (x > (xstart + xend) / 2)
		xflag = 1;
	if (y > (ystart + yend) / 2)
		yflag = 1;

	if (xflag == 0 && yflag == 0) {			// 0 구역
		strict = 0;
		xend = (xstart + xend) / 2;
		yend = (ystart + yend) / 2;
	}
	else if (xflag == 1 && yflag == 0) {		// 1구역
		strict = 1;
		xstart = xstart + size/2;
		yend = (ystart + yend) / 2;
	}
	else if (xflag == 0 && yflag == 1) {		// 2구역
		strict = 2;
		xend = (xstart + xend) / 2;
		ystart = ystart + size / 2;
	}
	else {			// 3구역
		strict = 3;
		xstart = xstart + size / 2;
		ystart = ystart + size / 2;
	}
	
	ans_square += strict * pow(2, N - 1) * pow(2, N - 1);

	re_square(y, x, N - 1, xstart, xend, ystart, yend);
}

int bj_1074() {
	ans_square = 0;
	int N, x, y, size;
	cin >> N;
	cin >> y >> x;
	size = pow(2, N) - 1;
	re_square(y, x, N, 0, size, 0, size);

	return 0;
}