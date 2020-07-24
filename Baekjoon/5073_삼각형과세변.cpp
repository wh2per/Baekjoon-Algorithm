#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		for (int i = 0; i < 3; i++)
			cin >> arr[i];

		if (arr[0] == 0 && arr[0] == arr[1] && arr[0] == arr[2])
			break;
		sort(arr, arr + 3);//오름차순으로 정렬

		if (arr[2] >= arr[1] + arr[0])
			cout << "Invalid" << '\n';
		else if (arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2])
			cout << "Scalene" << '\n';
		else
		{
			if (arr[0] == arr[1] && arr[1] == arr[2])
				cout << "Equilateral" << '\n';
			else
				cout << "Isosceles" << '\n';
		}
	}

	return 0;
}


