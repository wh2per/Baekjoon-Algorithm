#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bj_10989() {
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> v(10001,0);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		++v[x];
	}

	for (int i = 1; i < 10001; i++) {
		if (v[i] > 0) {
			for(int j=0; j<v[i]; j++)
				cout << i << '\n';
		}
	}
	return 0;
}