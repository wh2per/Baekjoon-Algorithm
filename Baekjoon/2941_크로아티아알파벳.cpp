#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	
using namespace std;

int main() {
	vector<string> v = { "c=","c-","dz=","d-","lj","nj","s=","z="};
	string s;
	cin >> s;
	int size = s.length();

	for (int i = 0; i < size; i++) {
		for (string c : v) {
			if (s.find(c) != string::npos) {
				int index = 0;
				index = s.find(c);
				s.erase(index, c.length());
				s.insert(index, "#");
			}
		}
	}
	cout << s.length();
	return 0;
}