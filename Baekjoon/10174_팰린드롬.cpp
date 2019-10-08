#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string temp;
	int n;
	cin >> n;
	getline(cin, temp);

	for (int i = 0; i < n; ++i) {
		string p;
		getline(cin, p);
		while (p.back() == ' ')
			p.pop_back();
		string str = "";
		for (int i = 0; i < p.size(); i++)
		{
			p[i] = tolower(p[i]);
			str = p[i] + str;
		}

		if (str == p)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}