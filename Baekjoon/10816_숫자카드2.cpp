#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> card(n);
	for (int i = 0; i < n; ++i) 
		cin >> card[i];

	sort(card.begin(), card.end());

	int m;
	cin >> m;
	
	for (int i = 0; i < m; ++i){
		int num;
		cin >> num;
		cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << " ";
	}

	return 0;
}