#include <iostream>
using namespace std;

int inOrder[100001];
int postOrder[100001];
int preOrder[100001];

void go(int ins, int ine, int posts, int poste) {
	if (ins > ine || posts > poste)
		return;

	int root = postOrder[poste];
	cout << root << " ";

	// 왼쪽 자식
	go(ins, preOrder[root] - 1, posts, posts + (preOrder[root] - ins) - 1);

	// 오른쪽 자식
	go(preOrder[root] + 1, ine, posts + (preOrder[root] - ins), poste - 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> inOrder[i];

	for (int i = 0; i < n; ++i)
		cin >> postOrder[i];

	for (int i = 0; i < n; ++i)
		preOrder[inOrder[i]] = i;

	go(0, n - 1, 0, n - 1);
	return 0;
}