#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> A;

void manachers(string S, int N)
{
	int r = 0, p = 0;
	for (int i = 0; i < N; i++)
	{
		if (i <= r)
			A[i] = min(A[2 * p - i], r - i);
		else
			A[i] = 0;

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1])
			A[i]++;

		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string p;
	cin >> p;

	string str = "";
	for (int i = 0; i < p.size(); i++)
	{
		str += '#';
		str += p[i];
	}
	str += '#';

	A.assign(str.size(), 0);
	manachers(str, str.size());

	int ans = -1;
	for (int i = 0; i < str.size(); i++)
		ans = max(ans, A[i]);

	cout << ans;
	return 0;
}
