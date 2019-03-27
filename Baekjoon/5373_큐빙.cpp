#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct CUBE {
	vector<vector<vector<char>>> cube;			// 0:앞 1:뒤 2:위 3:아래 4:오른 5:왼

	void init() {
		cube.resize(6, vector<vector<char>>(3, vector<char>(3, 0)));
		vector<char> v = {'r','o','w','y','b','g'};
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k)
					cube[i][j][k] = v[i];
			}
		}
	}

	void printUP() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j)
				cout << cube[2][i][j];
			cout << '\n';
		}
	}

	void rotate(string s) {
		if (s[0] == 'F') {					// 앞쪽면 회전
			vector<vector<char>> temp(3, vector<char>(3));
			if (s[1] == '+') {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[0][3 - x - 1][y];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[0][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][0][2], cube[5][1][2], cube[5][2][2] };		// 왼쪽면 값 저장
				cube[5][0][2] = cube[3][2][2];		// 왼쪽면 수정
				cube[5][1][2] = cube[3][2][1];
				cube[5][2][2] = cube[3][2][0];

				cube[3][2][2] = cube[4][2][0];		// 아래쪽면 수정
				cube[3][2][1] = cube[4][1][0];
				cube[3][2][0] = cube[4][0][0];

				cube[4][2][0] = cube[2][2][2];		// 오른쪽면 수정
				cube[4][1][0] = cube[2][2][1];
				cube[4][0][0] = cube[2][2][0];

				cube[2][2][2] = t[0];				// 위쪽면 수정
				cube[2][2][1] = t[1];
				cube[2][2][0] = t[2];
			}
			else {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[0][x][3 - y - 1];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[0][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][0][2], cube[5][1][2], cube[5][2][2] };		// 왼쪽면 값 저장
				cube[5][0][2] = cube[2][2][2];		// 왼쪽면 수정
				cube[5][1][2] = cube[2][2][1];
				cube[5][2][2] = cube[2][2][0];
				
				cube[2][2][2] = cube[4][2][0];		// 위쪽면 수정
				cube[2][2][1] = cube[4][1][0];
				cube[2][2][0] = cube[4][0][0];
				
				cube[4][2][0] = cube[3][2][2];		// 오른쪽면 수정
				cube[4][1][0] = cube[3][2][1];
				cube[4][0][0] = cube[3][2][0];

				cube[3][2][2] = t[0];				// 아래쪽면 수정
				cube[3][2][1] = t[1];
				cube[3][2][0] = t[2];
			}
		}
		else if (s[0] == 'B') {				// 뒤쪽면 회전
			vector<vector<char>> temp(3, vector<char>(3));
			if (s[1] == '+') {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[1][3 - x - 1][y];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[1][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][0][0], cube[5][1][0], cube[5][2][0] };		// 왼쪽면 값 저장
				cube[5][0][0] = cube[2][0][2];		// 왼쪽면 수정
				cube[5][1][0] = cube[2][0][1];
				cube[5][2][0] = cube[2][0][0];

				cube[2][0][2] = cube[4][2][2];		// 위쪽면 수정
				cube[2][0][1] = cube[4][1][2];
				cube[2][0][0] = cube[4][0][2];

				cube[4][2][2] = cube[3][0][2];		// 오른쪽면 수정
				cube[4][1][2] = cube[3][0][1];
				cube[4][0][2] = cube[3][0][0];

				cube[3][0][2] = t[0];				// 아래쪽면 수정
				cube[3][0][1] = t[1];
				cube[3][0][0] = t[2];
			}
			else {							
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[1][x][3 - y - 1];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[1][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][0][0], cube[5][1][0], cube[5][2][0] };		// 왼쪽면 값 저장
				cube[5][0][0] = cube[3][0][2];		// 왼쪽면 수정
				cube[5][1][0] = cube[3][0][1];
				cube[5][2][0] = cube[3][0][0];

				cube[3][0][2] = cube[4][2][2];		// 아래쪽면 수정
				cube[3][0][1] = cube[4][1][2];
				cube[3][0][0] = cube[4][0][2];

				cube[4][2][2] = cube[2][0][2];		// 오른쪽면 수정
				cube[4][1][2] = cube[2][0][1];
				cube[4][0][2] = cube[2][0][0];

				cube[2][0][2] = t[0];				// 위쪽면 수정
				cube[2][0][1] = t[1];
				cube[2][0][0] = t[2];
			}
		}
		else if (s[0] == 'U') {					// 위쪽면 회전
			vector<vector<char>> temp(3, vector<char>(3));
			if (s[1] == '+') {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[2][3 - x - 1][y];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[2][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][0][2], cube[5][0][1], cube[5][0][0] };		// 왼쪽면 값 저장
				cube[5][0][2] = cube[0][0][2];		// 왼쪽면 수정
				cube[5][0][1] = cube[0][0][1];
				cube[5][0][0] = cube[0][0][0];

				cube[0][0][2] = cube[4][0][2];		// 앞쪽면 수정
				cube[0][0][1] = cube[4][0][1];
				cube[0][0][0] = cube[4][0][0];

				cube[4][0][2] = cube[1][0][2];		// 오른쪽면 수정
				cube[4][0][1] = cube[1][0][1];
				cube[4][0][0] = cube[1][0][0];

				cube[1][0][2] = t[0];				// 뒤쪽면 수정
				cube[1][0][1] = t[1];
				cube[1][0][0] = t[2];
			}
			else {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[2][x][3 - y - 1];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[2][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][0][2], cube[5][0][1], cube[5][0][0] };		// 왼쪽면 값 저장
				cube[5][0][2] = cube[1][0][2];		// 왼쪽면 수정
				cube[5][0][1] = cube[1][0][1];
				cube[5][0][0] = cube[1][0][0];

				cube[1][0][2] = cube[4][0][2];		// 뒤쪽면 수정
				cube[1][0][1] = cube[4][0][1];
				cube[1][0][0] = cube[4][0][0];

				cube[4][0][2] = cube[0][0][2];		// 오른쪽면 수정
				cube[4][0][1] = cube[0][0][1];
				cube[4][0][0] = cube[0][0][0];

				cube[0][0][2] = t[0];				// 앞쪽면 수정
				cube[0][0][1] = t[1];
				cube[0][0][0] = t[2];
			}
		}
		else if (s[0] == 'D') {					// 아래쪽면 회전
			vector<vector<char>> temp(3, vector<char>(3));
			if (s[1] == '+') {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[3][3 - x - 1][y];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[3][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][2][2], cube[5][2][1], cube[5][2][0] };		// 왼쪽면 값 저장
				cube[5][2][2] = cube[1][2][2];		// 왼쪽면 수정
				cube[5][2][1] = cube[1][2][1];
				cube[5][2][0] = cube[1][2][0];

				cube[1][2][2] = cube[4][2][2];		// 뒤쪽면 수정
				cube[1][2][1] = cube[4][2][1];
				cube[1][2][0] = cube[4][2][0];

				cube[4][2][2] = cube[0][2][2];		// 오른쪽면 수정
				cube[4][2][1] = cube[0][2][1];
				cube[4][2][0] = cube[0][2][0];

				cube[0][2][2] = t[0];				// 앞쪽면 수정
				cube[0][2][1] = t[1];
				cube[0][2][0] = t[2];
			}
			else {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[3][x][3 - y - 1];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[3][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[5][2][2], cube[5][2][1], cube[5][2][0] };		// 왼쪽면 값 저장
				cube[5][2][2] = cube[0][2][2];		// 왼쪽면 수정
				cube[5][2][1] = cube[0][2][1];
				cube[5][2][0] = cube[0][2][0];

				cube[0][2][2] = cube[4][2][2];		// 앞쪽면 수정
				cube[0][2][1] = cube[4][2][1];
				cube[0][2][0] = cube[4][2][0];

				cube[4][2][2] = cube[1][2][2];		// 오른쪽면 수정
				cube[4][2][1] = cube[1][2][1];
				cube[4][2][0] = cube[1][2][0];

				cube[1][2][2] = t[0];				// 앞쪽면 수정
				cube[1][2][1] = t[1];
				cube[1][2][0] = t[2];
			}
		}
		else if (s[0] == 'R') {					// 오른쪽면 회전
			vector<vector<char>> temp(3, vector<char>(3));	
			if (s[1] == '+') {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[4][3 - x - 1][y];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[4][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[2][0][2], cube[2][1][2], cube[2][2][2] };		// 위쪽면 값 저장
				cube[2][0][2] = cube[0][0][2];		// 위쪽면 수정
				cube[2][1][2] = cube[0][1][2];
				cube[2][2][2] = cube[0][2][2];

				cube[0][0][2] = cube[3][2][0];		// 앞쪽면 수정
				cube[0][1][2] = cube[3][1][0];
				cube[0][2][2] = cube[3][0][0];

				cube[3][2][0] = cube[1][2][0];		// 아래쪽면 수정
				cube[3][1][0] = cube[1][1][0];
				cube[3][0][0] = cube[1][0][0];

				cube[1][2][0] = t[0];				// 뒤쪽면 수정
				cube[1][1][0] = t[1];
				cube[1][0][0] = t[2];
			}
			else {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[4][x][3 - y - 1];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[4][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[2][0][2], cube[2][1][2], cube[2][2][2] };		// 위쪽면 값 저장
				cube[2][0][2] = cube[1][2][0];		// 위쪽면 수정
				cube[2][1][2] = cube[1][1][0];
				cube[2][2][2] = cube[1][0][0];

				cube[1][2][0] = cube[3][2][0];		// 뒤쪽면 수정
				cube[1][1][0] = cube[3][1][0];
				cube[1][0][0] = cube[3][0][0];

				cube[3][2][0] = cube[0][0][2];		// 아래쪽면 수정
				cube[3][1][0] = cube[0][1][2];
				cube[3][0][0] = cube[0][2][2];

				cube[0][0][2] = t[0];				// 앞쪽면 수정
				cube[0][1][2] = t[1];
				cube[0][2][2] = t[2];
			}
		}
		else if (s[0] == 'L') {					// 왼쪽면 회전
			vector<vector<char>> temp(3, vector<char>(3));
			if (s[1] == '+') {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[5][3 - x - 1][y];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[5][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[2][0][0], cube[2][1][0], cube[2][2][0] };		// 위쪽면 값 저장
				cube[2][0][0] = cube[1][2][2];		// 위쪽면 수정
				cube[2][1][0] = cube[1][1][2];
				cube[2][2][0] = cube[1][0][2];

				cube[1][2][2] = cube[3][2][2];		// 뒤쪽면 수정
				cube[1][1][2] = cube[3][1][2];
				cube[1][0][2] = cube[3][0][2];

				cube[3][2][2] = cube[0][0][0];		// 아래쪽면 수정
				cube[3][1][2] = cube[0][1][0];
				cube[3][0][2] = cube[0][2][0];

				cube[0][0][0] = t[0];				// 앞쪽면 수정
				cube[0][1][0] = t[1];
				cube[0][2][0] = t[2];
			}
			else {
				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						temp[y][x] = cube[5][x][3 - y - 1];
					}
				}

				for (int y = 0; y < 3; ++y) {
					for (int x = 0; x < 3; ++x) {
						cube[5][y][x] = temp[y][x];
					}
				}

				vector<char> t = { cube[2][0][0], cube[2][1][0], cube[2][2][0] };		// 위쪽면 값 저장
				cube[2][0][0] = cube[0][0][0];		// 위쪽면 수정
				cube[2][1][0] = cube[0][1][0];
				cube[2][2][0] = cube[0][2][0];

				cube[0][0][0] = cube[3][2][2];		// 앞쪽면 수정
				cube[0][1][0] = cube[3][1][2];
				cube[0][2][0] = cube[3][0][2];

				cube[3][2][2] = cube[1][2][2];		// 아래쪽면 수정
				cube[3][1][2] = cube[1][1][2];
				cube[3][0][2] = cube[1][0][2];

				cube[1][2][2] = t[0];				// 뒤쪽면 수정
				cube[1][1][2] = t[1];
				cube[1][0][2] = t[2];
			}
		}
	}
};

int bj_5373() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		CUBE cb;
		cb.init();
		int r;
		cin >> r;
		string s,str;
		getline(cin, s);		// 이전 개행문자 날리기
		getline(cin, s);
		stringstream ss(s);
		while (ss >> str)
			cb.rotate(str);
		cb.printUP();
	}

	return 0;
}