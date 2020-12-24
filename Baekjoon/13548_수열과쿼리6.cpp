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

struct Query {
	int idx, s, e;
	Query(int idx, int s, int e) : idx(idx), s(s), e(e) {}
};

int sqrtN;

bool cmp(Query& x1, Query& x2) {
	if (x1.e / sqrtN == x2.e / sqrtN)
		return x1.s < x2.s;
	return x1.e / sqrtN < x2.e / sqrtN;
}
// 쿼리가 끝나는 부분이 어떠한 묶음에 속하는지 확인하다
// 묶음의 인덱스가 더 작은곳에 속하는 쿼리를 먼저 처리한다
// 만약 묶음의 인덱스가 같다면 쿼리의 시작지점이 작은것을 먼저 처리한다
vector<Query> query;

int n, q;
int mcnt;
int v[1000001];
int cnt[1000001];
int ans[1000001];
int table[1000001];	 // table[3] = 5이면, 구간내에서 3번 등장하는 수가 5종류가 있다는 것

void sub(int num) {
	if (mcnt == cnt[num] && table[mcnt] == 1)	// mcnt가 num의 빈도수 이면서 이 빈도수를 가진 수가 1개뿐일 경우 
		--mcnt;
	--table[cnt[num]];		// num의 빈도수를 가진 숫자를 하나 감소
	--cnt[num];				// num의 빈도수 감소
	++table[cnt[num]];		// num의 빈도수를 가진 숫자 하나 증가
}

void add(int num) {
	--table[cnt[num]];		// num의 빈도수를 가진 숫자를 하나 감소 (얘는 이제 과거 데이터이기 때문)
	++cnt[num];				// num의 빈도수 증가
	++table[cnt[num]];		// num의 빈도수를 가진 숫자를 하나 증가 (얘가 현재 데이터이기 때문)

	if (mcnt < cnt[num])	// 어차피 한개씩 검사하므로 증가도 1개씩함
		++mcnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int start, end;
		cin >> start >> end;
		query.emplace_back(i, start - 1, end - 1);
	}
	sqrtN = sqrt(n);
	sort(query.begin(), query.end(), cmp);			// 쿼리 정렬

	int s = 0;
	int e = -1;
	mcnt = 0;

	for (auto a : query) {
		int ns = a.s;
		int ne = a.e;

		for (int i = s - 1; i >= ns; --i)	// s가 ns보다 오른쪽에 있는 경우 : 수를 더할 필요가 있다
			add(v[i]);
		for (int i = e + 1; i <= ne; ++i)	// e가 ne보다 왼쪽에 있는 경우 : 수를 더할 필요가 있다
			add(v[i]);
		for (int i = e; i > ne; --i)		// e가 ne보다 오른쪽에 있는 경우 : 수를 제거할 필요가 있다
			sub(v[i]);
		for (int i = s; i < ns; ++i)		// s가 ns보다 왼쪽에 있는 경우 : 수를 제거할 필요가 있다
			sub(v[i]);

		s = ns;
		e = ne;

		ans[a.idx] = mcnt;
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";

	return 0;
}