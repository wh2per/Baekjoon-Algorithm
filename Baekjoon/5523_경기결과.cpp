#include <iostream>
using namespace std;
int a, b, ac, bc, t;

int main() {
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (a > b) 
			ac++; 
		else if (a < b)
			bc++;
	}
	cout << ac << ' ' << bc << '\n';

	return 0;
}

