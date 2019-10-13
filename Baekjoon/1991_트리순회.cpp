#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int value;
	node* left;
	node* right;
};
struct node tree[26];

void preFix(node a) {
	cout << (char)(a.value + 'A');
	if (a.left != NULL) {
		preFix(*a.left);
	}
	if (a.right != NULL) {
		preFix(*a.right);
	}
}
void inOrder(node a) {
	if (a.left != NULL) {
		inOrder(*a.left);
	}
	cout << (char)(a.value + 'A');

	if (a.right != NULL) {
		inOrder(*a.right);
	}
}
void postFix(node a) {
	if (a.left != NULL) {
		postFix(*a.left);
	}
	if (a.right != NULL) {
		postFix(*a.right);
	}

	cout << (char)(a.value + 'A');

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (auto i = 0; i < n; i++) {
		tree[i].value = i;
	}
	for (auto i = 0; i < n; i++) {
		char value, left, right;
		cin >> value >> left >> right;

		if (left != '.')
			tree[value - 'A'].left = &tree[(left - 'A')];

		if (right != '.')
			tree[value - 'A'].right = &tree[(right - 'A')];

	}
	preFix(tree[0]);
	cout << '\n';
	inOrder(tree[0]);
	cout << '\n';
	postFix(tree[0]);

	return 0;
}