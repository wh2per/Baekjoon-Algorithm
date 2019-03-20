#include <iostream>
#include <string>
#include <vector>
using namespace std;

int bj_11365() {
	string str="";
	vector<string> v;

	while (str != "END") {
		getline(cin, str);
		v.push_back(str);
	}
	
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = v[i].length()-1; j >= 0; j--) {
			cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}