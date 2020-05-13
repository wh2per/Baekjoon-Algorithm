#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int n, c;
vector<int> v;


int calc(int mid) {
	int cnt = 1;
	int start = v[0];

	for (int i = 1; i < n; ++i) {
		int dist = v[i] - start;
		if (mid <= dist) {
			++cnt;
			start = v[i];
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> c;


	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	int low = 1;
	int high = v[n - 1] - v[0];
	int dist = 0;
	int ans = 0;

	while (low <= high) {
		int mid = (low + high) >> 1;
		int cnt = calc(mid);
		
		if (cnt >= c) {
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	
	cout << ans;
	return 0;
}