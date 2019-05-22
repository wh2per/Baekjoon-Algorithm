#include <iostream>
#include <vector>
using namespace std;

int bj_1158() {
	int n, m;
	cin >> n >> m;
	vector<int> people;
	vector<bool> check(n, false);

	for (int i = 0; i < n; ++i)
		people.push_back(i+1);

	int index = 0;
	int count = 1;
	int end = n;
	vector<int> answer;
 	while (end>0) {
		if (!check[index%n]) {
			if (count%m == 0) {
				answer.push_back(people[index%n]);
				check[index%n] = true;
				--end;
			}
			++count;
			++index;
		}
		else {
			while (check[index%n]) 
				++index;
		}
		
	}
	cout << "<";
	for (int i = 0; i < answer.size() - 1; ++i)
		cout << answer[i] << ", ";
	cout << answer.back() << ">";
	return 0;
}