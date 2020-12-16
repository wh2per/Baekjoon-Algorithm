#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int n;
int arr[500001];
int arr2[500001];
ll cnt;

ll merge_sort(int start, int end) {
	if (start == end)
		return 0;

	int mid = (start + end) >> 1;
	ll result = merge_sort(start, mid) + merge_sort(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid || j <= end)
	{
		if (i <= mid && (j > end || arr[i] <= arr[j]))
		{
			arr2[k++] = arr[i++];
		}
		else
		{
			// 왼쪽 배열의 남아있는 원소들의 개수
			result += (long long)(mid - i + 1);
			arr2[k++] = arr[j++];
		}
	}

	for (int i = start; i <= end; i++) {
		arr[i] = arr2[i - start];
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cnt = merge_sort(0, n - 1);

	cout << cnt;
	return 0;
}