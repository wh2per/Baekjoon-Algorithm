#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int n;
long long b;

vector<int> matMul(vector<int> &A, vector<int> &B) {
	vector<int> c(n * n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k)
				c[i * n + j] = (c[i*n+j] + A[i*n+k] * B[k*n+j]) % 1000;
		}
	}
	return c;
}

vector<int> solve(vector<int> &A, long long p) {
	if (p == 1)
		return A;
	vector<int> c = solve(A, p / 2);
	c = matMul(c, c);
	if (p % 2)
		c = matMul(c, A);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> b;

	vector<int> a(n * n);
	vector<int> ret;

	for (int i = 0; i < n * n; ++i)
		cin >> a[i];
	ret = solve(a,b);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ret[i * n + j] % 1000<<" ";
		}
		cout << "\n";
	}



	return 0;
}