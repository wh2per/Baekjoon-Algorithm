#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int preorder[1001];
int inorder[1001];

void postorder(int start, int end, int pos) {
	for (int i = start; i < end; ++i) {
		if (preorder[pos] == inorder[i]) {		// root
			postorder(start, i, pos + 1);
			postorder(i + 1, end, pos + i + 1 - start);
			cout << inorder[i] << ' ';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; ++t) {
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> preorder[i];
		}

		for (int i = 0; i < n; ++i) {
			cin >> inorder[i];
		}

		postorder(0, n, 0);
		cout << '\n';
	}

	return 0;
}