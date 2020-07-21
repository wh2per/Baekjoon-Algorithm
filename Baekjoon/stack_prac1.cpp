#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	queue<int> q;
	queue<pair<int, int>> q2;


	priority_queue<int, vector<int>> pq;

	pq.push(6);
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	
	cout << pq.top();

	return 0;
}
