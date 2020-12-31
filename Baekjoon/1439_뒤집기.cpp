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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

    string s;
    int zero = 0, one = 0;

    cin >> s;

    if (s[0] == '0')
        zero++;
    else
        one++;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '0')
                zero++;
            else
                one++;
        }
    }
    cout << min(zero, one);

	return 0;
}