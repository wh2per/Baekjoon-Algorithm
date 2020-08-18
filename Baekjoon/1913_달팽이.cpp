#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int mat[1000][1000]; 
int N; 
int num; 
int i = 1; 
int j = 1; 
int direction = 1; 
int what; 
int a, b; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	cin >> what;
	num = N * N;

	while (num) {
		if (what == num) { 
			a = i;
			b = j;
		}
		if (j - i == 1 && i <= (N / 2) + 1 && j - 1 != (N / 2 + 1)) { 
			mat[i][j] = num;
			i = i + 1;
		}
		else if (i == j && (N / 2 + 1) >= i) { 
			direction = 1; //го
			mat[i][j] = num;
			i = i + 1;
		}
		else if (i == j && (N / 2 + 1) < i) { 
			direction = 2; //╩С
			mat[i][j] = num;
			i = i - 1;
		}
		else if (i + j == N + 1 && i > j) { 
			direction = 3; //©Л
			mat[i][j] = num;
			j = j + 1;
		}
		else if (i + j == N + 1 && i < j) { 
			direction = 4; //аб
			mat[i][j] = num;
			j = j - 1;
		}
		else { 
			mat[i][j] = num;
			if (direction == 1) 
				i = i + 1;
			if (direction == 2) 
				i = i - 1;
			if (direction == 3) 
				j = j + 1;
			if (direction == 4) 
				j = j - 1;
		}
		num--; 
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) 
			cout << mat[i][j] << ' ';
		cout << '\n';
	}
	cout << a << ' ' << b;

	return 0;
}