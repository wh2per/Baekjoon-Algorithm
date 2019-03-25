#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {0,1,0,-1,0};
const int dy[] = {-1,0,1,0,0};

int bj_3190() {
	int ans = 0;
	pair<int, int> head = make_pair(1,1);
	pair<int, int> tail = make_pair(1,1);
	int cdir = 1;	// 초기는 오른쪽
	int tdir = 1;
	int N, K, L;
	cin >> N >>K;
	vector<vector<int>> snake_map(N+1, vector<int>(N+1,0));
	for (int i = 0; i < K; i++) {		// 맵 입력, 사과 위치 저장
		int x, y;
		cin >> y >> x;
		snake_map[y][x] = 1;
	}
	cin >> L;
	queue<pair<int, char>> q;			// 방향전환 시기,방향 저장
	for (int i = 0; i < L; i++) {
		int time;
		char dir;
		cin >> time >> dir;
		q.push(make_pair(time, dir));
	}

	snake_map[1][1] = 2;
	queue<int> tail_dir;

	while (!q.empty()) {
		int time = q.front().first;
		char ndir = q.front().second;
		q.pop();

		while (ans < time) {
			++ans;
			head.first += dy[cdir];
			head.second += dx[cdir];
			tail_dir.push(cdir);

			if (head.first<1 || head.first>N || head.second<1 || head.second>N) {		// 종료 조건 - 벽에 박치기
				cout << ans;
				return 0;
			}

			if (snake_map[head.first][head.second] == 2) {			// 종료 조건 - 몸통이랑 부딪힘
				cout << ans;
				return 0;
			}

			if (snake_map[head.first][head.second] != 1) {			// 사과가 아님
				snake_map[tail.first][tail.second] = 0;
				if(!tail_dir.empty()){ 
					tdir = tail_dir.front();
					tail_dir.pop();
					tail.first += dy[tdir];
					tail.second += dx[tdir];
				}
			}

			snake_map[head.first][head.second] = 2;
		}
		
		if (ndir == 'L') 
			cdir = (cdir + 3) % 4;
		else
			cdir = (cdir + 1) % 4;


	}

	while (1) {
		++ans;
		head.first += dy[cdir];
		head.second += dx[cdir];
		tail_dir.push(cdir);

		if (head.first<1 || head.first>N || head.second<1 || head.second>N) {		// 종료 조건 - 벽에 박치기
			cout << ans;
			return 0;
		}

		if (snake_map[head.first][head.second] == 2) {			// 종료 조건 - 몸통이랑 부딪힘
			cout << ans;
			return 0;
		}

		if (snake_map[head.first][head.second] != 1) {			// 사과가 아님
			snake_map[tail.first][tail.second] = 0;
			tdir = tail_dir.front();
			tail_dir.pop();
			tail.first += dy[tdir];
			tail.second += dx[tdir];
		}

		snake_map[head.first][head.second] = 2;
	}

	return 0;
}