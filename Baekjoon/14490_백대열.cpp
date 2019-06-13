#include <iostream>
#include <string>
#include <vector>
using namespace std;

int bj_14490() {
	string s;
	cin >> s;
	int index = s.find(":");
	int a = stoi(s.substr(0, index));
	int b = stoi(s.substr(index + 1, s.length()));
	
	int g = a;
	int t = b;
	int c;
	while (t != 0)
	{
		c = g % t;
		g = t;
		t = c;
	}

	a /= g;
	b /= g;
	cout << a << ":" << b;
	return 0;
}