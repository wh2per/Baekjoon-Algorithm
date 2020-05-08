#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;

	set<string> s;

	while (n--) {
		string name, inout;

		cin >> name >> inout;

		if (inout == "enter")
			s.insert(name);
		else
			s.erase(name);
	}

	for (auto it = s.rbegin(); it != s.rend(); it++)			// 이터레이터로 도는것이 더 빠름
		cout << *it << "\n";

	return 0;
}