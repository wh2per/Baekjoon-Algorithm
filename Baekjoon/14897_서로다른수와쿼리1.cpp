#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

int sqrtN;
struct Query {
	int idx, s, e;
};

bool cmp(Query& x1, Query& x2) {
	if (x1.s / sqrtN != x2.s / sqrtN)
		return x1.s / sqrtN < x2.s / sqrtN;
	return x1.e < x2.e;
}

vector<Query> query;
vector<int> v;
vector<int> temp;
vector<int> ans;

int n, q;
int now = 0;
int mp[1000001];

void sub(int num) {
	--mp[v[num]];
	if (mp[v[num]] == 0)
		--now;
}

void add(int num) {
	if (mp[v[num]] == 0)
		++now;
	++mp[v[num]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);

	cin >> n;
	v.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	temp = v;

	sort(temp.begin() + 1, temp.end());
	temp.erase(unique(temp.begin() + 1, temp.end()), temp.end());		// 중복제거

	for (int i = 1; i <= n; ++i)
		v[i] = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();	// v[i]가 몇번째 수인지 저장

	cin >> q;
	query.resize(q);
	ans.assign(q, 0);
	for (int i = 0; i < q; ++i) {
		cin >> query[i].s >> query[i].e;
		query[i].idx = i;
	}
	sqrtN = sqrt(n);
	sort(query.begin(), query.end(), cmp);			// 쿼리 정렬

	int s = query[0].s;
	int e = query[0].e;
	int idx = query[0].idx;

	for (int i = s; i <= e; i++)
		add(i);
	ans[idx] = now;

	for (int i = 1; i < q; ++i) {
		idx = query[i].idx;
		while (s < query[i].s)
			sub(s++);
		while (s > query[i].s)
			add(--s);
		while (e < query[i].e)
			add(++e);
		while (e > query[i].e)
			sub(e--);
		ans[idx] = now;
	}

	for (auto i : ans)
		cout << i << "\n";

	return 0;
}