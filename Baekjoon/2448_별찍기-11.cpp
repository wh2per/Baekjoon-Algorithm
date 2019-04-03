#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int bj_2448() {
	vector<string> tri = { "  *  "," * * ","*****" };

	int n;
	cin >> n;
	int num = n / 3;
	int repeat;
	
	if (num == 1)
		repeat = 0;
	else {
		int a = 1;
		for (repeat = 1; repeat <= 10; ++repeat) {
			if (a * 2 == num)
				break;
			else
				a *= 2;
		}
	}
	vector<string> temp(tri.begin(), tri.end());
	
	for (int i = 0; i < repeat; ++i) {
		for (int j = 0; j < tri.size(); ++j) {
			string s = "";
			for (int k = 0; k < pow(2,i); ++k) 
				s += "   ";
			temp[j] = s + temp[j] + s;
			temp.push_back(tri[j] + " " + tri[j]);
		}
		tri = temp;
	}

	for (int i = 0; i < tri.size(); ++i) {
		for (char c : tri[i])
			cout << c;
		cout << '\n';
	}
	return 0;
}