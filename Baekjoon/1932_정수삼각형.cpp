#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int bj_1932() {
	int n;
	cin >> n;

	vector<vector<int>> triangle;

	for (int i = 1; i <= n; ++i) {
		vector<int> v;
		for (int j = 0; j < i; ++j) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		triangle.push_back(v);
	}

	int answer = triangle[0][0];

	if (triangle.size() == 1)
		return answer;

	for (int i = 1; i < triangle.size(); i++) {			
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				triangle[i][j] += triangle[i - 1][j];
			else if (j == triangle[i].size() - 1)
				triangle[i][j] += triangle[i - 1][j - 1];
			else
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < triangle.size(); i++) {
		if (answer < triangle[triangle.size() - 1][triangle.size() - 1 - i])
			answer = triangle[triangle.size() - 1][triangle.size() - 1 - i];
	}

	cout << answer;
	return 0;
}

