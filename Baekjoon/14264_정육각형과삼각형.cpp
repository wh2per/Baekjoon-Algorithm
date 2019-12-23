#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	double PI = 3.1415926535897;

	double d;
	cin >> d;

	printf("%.14f",cos(30*(PI/180)) * d * d / 2);

	return 0;
}