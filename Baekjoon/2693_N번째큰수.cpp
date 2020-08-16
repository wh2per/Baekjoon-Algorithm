#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
    int n;
    vector<int> v(10);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            cin >> v[j];
        sort(v.begin(), v.end());

        cout << v[7] << endl;
    }

    return 0;
}