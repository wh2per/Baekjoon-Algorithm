#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int dragon_dx[] = { 1,0,-1,0 };		// 문제상 0 3 2 1 방향 
const int dragon_dy[] = { 0,-1,0,1 };		// 오른쪽 위 왼쪽 아래 (순차적으로 반시계90 회전방향0
bool dragon_map[200][200];
int dragon_ans;

void dragon_curve(int x, int y, int dir, int gen, stack<int> s) {
	int tdir=0;
	if (gen == 0)
		return;
	
	stack<int> next_s = s;

	while (!s.empty()) {
		int tdir = s.top();
		s.pop();
		tdir = (tdir + 1) % 4;		// 다음 dir로 변경. 즉, 반시계 90로 회전

		next_s.push(tdir);
		x += dragon_dx[tdir];
		y += dragon_dy[tdir];
		dragon_map[y][x] = true;
	}
	dragon_curve(x, y, tdir, gen - 1, next_s);
}

void dragon_check() {
	for (int i = 0; i < 199; ++i) {
		for (int j = 0; j < 199; ++j) {
			if (dragon_map[i][j]) {
				if (dragon_map[i][j + 1] && dragon_map[i + 1][j] && dragon_map[i + 1][j + 1]) {
					++dragon_ans;
					continue;
				}
			}
		}
	}
}

int bj_15685() {
	int N;
	cin >> N;

	for (int i=0; i < N; i++) {
		int x, y, dir, gen;
		cin >> x >> y >> dir >> gen;
		
		dragon_map[y][x] = true;
		x += dragon_dx[dir];
		y += dragon_dy[dir];
		dragon_map[y][x] = true;
		
		if (gen > 0) {
			stack<int> s;
			s.push(dir);
			dragon_curve(x, y, dir, gen, s);
		}
	}

	dragon_check();

	cout << dragon_ans;
	return 0;
}