#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (!a && !b && !c)
			break;
		if (b - a == c - b && b - a != 0)
			cout << "AP " << b - a + c << '\n';
		else
			cout << "GP " << b / a * c << '\n';
	}
}


