#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int bj_11058() {
	int n;
	scanf("%d",&n);

	long long d[101] = {0,};

	for (int i = 1; i <= n; ++i) {
		d[i] = d[i - 1] + 1;
		for (int j = 1; j <= i - 3; ++j) {
			long long c = d[i - j - 2] * (j + 1);
			if (c > d[i])
				d[i] = c;
		}
	}
	printf("%ld",d[n]);
	return 0;
}