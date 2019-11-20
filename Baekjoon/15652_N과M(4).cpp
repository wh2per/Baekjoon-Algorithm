#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int arr[9];

bool check(){
	for (int i = 0; i < m-1; i++){
		if (arr[i] > arr[i + 1]) 
			return true;
	}
	return false;
}

void dfs(int cnt) {
	if (cnt == m) {
		if (m > 1 && check())
			return;
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> n >> m;

	dfs(0);

	return 0;
}