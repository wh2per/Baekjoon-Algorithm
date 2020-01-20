#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int arr[4];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	
	sort(arr, arr + 4);
	
	cout << arr[0] * arr[2] << endl;

	return 0;
}