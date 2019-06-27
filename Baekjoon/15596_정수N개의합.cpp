#include <iostream>
#include <vector>
using namespace std;

long long bj_15596(std::vector<int> &a) {
	long long ans = 0;
	for (auto n : a)
		ans += n;
	return ans;
}