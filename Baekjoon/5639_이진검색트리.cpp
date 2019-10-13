#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int left=0;
	int right=0;
};
node tree[1000001];

void postOrder(int pos) {
	if (tree[pos].left != 0)
		postOrder(tree[pos].left);

	if (tree[pos].right != 0)
		postOrder(tree[pos].right);
	
	cout << pos << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int input;
	cin >> input;
	int root = input;

	while (cin >> input) {
		int index = root; 

		while (1) {
			if (index < input) {
				if (tree[index].right != 0) 
					index = tree[index].right;
				else {
					tree[index].right = input;
					break;
				}
			}
			else {
				if (tree[index].left != 0) 
					index = tree[index].left;
				else {
					tree[index].left = input;
					break;
				}
			}
		}
	}

	postOrder(root);
	return 0;
}