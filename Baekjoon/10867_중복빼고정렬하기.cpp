#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

const int MAX = 2001; 
bool visited[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int N; 
	cin >> N; 
	
	vector<int> v; 
	for (int i = 0; i < N; i++) { 
		int num; 
		cin >> num; 
		if (!visited[num + 1000]) { 
			v.push_back(num); 
			visited[num + 1000] = true; 
		} 
	} 
	
	sort(v.begin(), v.end()); 
	
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " "; 

	return 0;
}