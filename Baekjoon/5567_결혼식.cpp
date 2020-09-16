#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

vector<int> friends[501];
bool friendsCheck[501];

void dfs(int n){
    //nodeNum의 친구 파악
    for (int i = 0; i < friends[n].size(); i++){
        int next = friends[n][i];
        friendsCheck[next] = true;
    }

    //1번의 친구의 친구를 찾는다
    if (n == 1) {
        for (int i = 0; i < friends[n].size(); i++) {
            int next = friends[n][i];
            dfs(next);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    dfs(1);
    int cnt = 0;

    for (int i = 2; i <= N; i++) {
        if (friendsCheck[i])
            cnt++;
    }

    cout << cnt << endl;
	return 0;
}