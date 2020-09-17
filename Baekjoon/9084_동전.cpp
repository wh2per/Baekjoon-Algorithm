#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

int coin[21];
int d[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int t;
	cin >> t;

    while(t--) {
        int N,M;
        cin >> N;

        for (int n = 1; n <= N; n++) 
            cin >> coin[n];
        cin >> M;

        memset(d, 0, sizeof(d));
        d[0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = coin[i]; j <= M; j++) {
                d[j] += d[j - coin[i]];
            }
        }
        cout << d[M] << endl;
    }

	return 0;
}