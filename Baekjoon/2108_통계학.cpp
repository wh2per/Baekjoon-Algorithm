#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int bj_2108() {
	vector<int> v;
	vector<int> number(8001,0);
	int n;
	int maxNum = -4000, minNum = 4000;
	int sum=0;

	cin >> n;
	for(int i=0; i<n; ++i){
		int num;
		cin >> num;
		sum += num;
		if (num >= 0)
			++number[num];
		else
			++number[-(num) + 4000];
		v.push_back(num);
		maxNum = max(maxNum, num);
		minNum = min(minNum, num);
	}
	sort(v.begin(), v.end());

	// Æò±Õ°ª
	printf("%.0f\n", (double)sum / n);
	//cout << (double)sum/n << "\n";

	// Áß¾Ó°ª
	cout << v[n/2] << "\n";

	// ÃÖºó°ª
	int b = 0;
	for (int i = 0; i < 8001; ++i) {
		if (number[i] > b) 
			b = number[i];
	}
	vector<int> ans;
	for (int i = 0; i < 8001; ++i) {
		if (number[i] == b) {
			if (i > 4000)
				ans.push_back(-(i - 4000));
			else
				ans.push_back(i);
		}
	}
	
	if (ans.size() == 1)
		cout << ans[0] << "\n";
	else {
		sort(ans.begin(), ans.end());
		cout << ans[1] << "\n";
	}

	// ¹üÀ§
	if (n == 1)
		cout << 0 << "\n";
	else
		cout << v[n - 1] - v[0] << "\n";

	return 0;
}