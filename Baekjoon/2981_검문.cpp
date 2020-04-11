// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end(),greater<int>());

	int ans = v[0] - v[1];

	for (int i = 2; i < v.size()-1; ++i)		// 모든 수의 최대공약수 구하기
		ans = gcd(ans, v[i]-v[i+1]);

	vector<int> nums;

	for (int i = 2; i * i <= ans; ++i) {
		if (ans % i == 0) {
			nums.push_back(i);
			if (ans / i != i)
				nums.push_back(ans / i);
		}
	}
	nums.push_back(ans);

	sort(nums.begin(), nums.end());

	for (auto a : nums)
		cout << a << " ";

    return 0;
}
