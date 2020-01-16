#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cy = 100, sd = 100, a, b;
	cin >> n;
	
	while(n--){
		cin >> a >> b;
		if (a > b) 
			sd -= a;
		else if(a<b)
			cy -= b;
	}
	cout << cy << "\n" << sd;

	return 0;
}