#include <iostream>
#include <vector>
using namespace std;

bool prime_check[1000001];

int bj_6588() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> prime;
	int temp = 1000000;
	int pn = 0;
	for (int i = 2; i*i <= temp; ++i) {
		if (!prime_check[i]) {
			for (int j = i * i; j <= temp; j += i) 
				prime_check[j] = true;
		}
	}
	prime_check[1] = true;
	for (int i = 2; i <= temp; ++i) {
		if (!prime_check[i])
			prime.push_back(i);
	}

	while (1) {
		int num;
		cin >> num;
		if (num == 0)
			break;
		bool flag = false;

		for (int j = 0; j < prime.size(); ++j) {
			if (!prime_check[num-prime[j]]) {
				cout << num << " = " << prime[j] << " + " << num - prime[j] << '\n';
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}
	

	return 0;
}