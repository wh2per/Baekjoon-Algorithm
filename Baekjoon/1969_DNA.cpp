#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

int DNA[51][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    string ans = "";
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < m; ++j) {
            if (s[j] == 'A')
                ++DNA[j][0];
            else if (s[j] == 'C')
                ++DNA[j][1];
            else if (s[j] == 'G')
                ++DNA[j][2];
            else
                ++DNA[j][3];
        }
    }

    for (int i = 0; i < m; ++i) {
        int index = 0;
        int mcnt = DNA[i][0];

        for (int j = 1; j < 4; ++j) {
            if (DNA[i][j] > mcnt) {
                index = j;
                mcnt = DNA[i][j];
            }
        }

        cnt += n - mcnt;

        if (index == 0)
            ans += "A";
        else if (index == 1)
            ans += "C";
        else if (index == 2)
            ans += "G";
        else
            ans += "T";
    }

    cout << ans << "\n" << cnt;;

    return 0;
}