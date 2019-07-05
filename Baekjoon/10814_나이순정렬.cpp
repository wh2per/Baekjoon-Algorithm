#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct info_people {
	int age;
	string name;
	int index;
};

bool people_cmp(info_people &ip1, info_people &ip2){
	if (ip1.age < ip2.age)
		return true;
	else if (ip1.age == ip2.age) {
		if (ip1.index < ip2.index)
			return true;
		else
			return false;
	}
	else
		return false;
}

int bj_10814() {
	int n;
	cin >> n;
	vector<info_people> v;

	for (int i = 0; i < n; ++i) {
		info_people ip;
		cin >> ip.age;
		cin >> ip.name;
		ip.index = i;
		v.push_back(ip);
	}
	sort(v.begin(), v.end(), people_cmp);
	for (auto a : v) 
		cout << a.age << " " << a.name << "\n";
	
	return 0;
}