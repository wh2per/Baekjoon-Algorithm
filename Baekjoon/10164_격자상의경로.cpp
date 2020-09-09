#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int a[16][16];
int d[16][16];

int main() {
    cin >> n >> m >> k;

    if (k != 0) {
        int t1, t2;

        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                count++;
                if (count == k) {
                    t1 = i;;
                    t2 = j;
                }
            }
        }

        d[1][1] = 1;
        for (int i = 1; i <= t1; i++) {
            for (int j = 1; j <= t2; j++) {
                if (i == 1 && j == 1)
                    continue;
                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }

        int result = d[t1][t2];

        // 초기화
        memset(d, 0, sizeof(d));

        // k번째 칸에서 n*m 번째 칸까지 점화식 수행
        d[t1][t2] = 1;
        for (int i = t1; i <= n; i++) {
            for (int j = t2; j <= m; j++) {
                if (i == t1 && j == t2) continue;

                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }
        cout << result * d[n][m];
    }
    else {
        d[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;
                d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        }
        cout << d[n][m];
    }

    return 0;
}