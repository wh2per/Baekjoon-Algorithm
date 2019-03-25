#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int chicken_dist = INT_MAX;
	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> chicken_map(N, vector<int>(N));

	for (int i = 0; i < N; i++) {			// map 입력받기
		for (int j = 0; j < N; j++) {
			cin >> chicken_map[i][j];
			if (chicken_map[i][j] == 1)			// 집 위치 저장
				house.push_back(make_pair(i, j));
			else if (chicken_map[i][j] == 2)	// 치킨집 위치 저장
				chicken.push_back(make_pair(i, j));
		}
	}

	vector<map<int, int>> hToc;

	// 집마다 치킨집까지 거리 계산
	for (int i = 0; i < house.size(); i++) {
		map<int, int> m;
		for (int j = 0; j < chicken.size(); j++) 
			m.insert(make_pair(j,abs(chicken[j].first-house[i].first)+abs(chicken[j].second-house[i].second)));
		hToc.push_back(m);
	}

	vector<int> v(chicken.size(), 1);
	for (int i = 0; i < M; i++)
		v[i] = 0;

	do {
		// 선택한 치킨집 기준으로 치킨거리 계산
		int temp = 0;
		vector<vector<int>> dist(house.size(),vector<int>());
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) {		// 선택한 치킨집일때. 치킨집 번호 : i
				for (int j = 0; j < house.size(); j++) {
					dist[j].push_back(hToc[j][i]);			// 각 집마다 해당 치킨집까지 거리를 저장
				}
			}
		}
		
		for (int i = 0; i < dist.size(); i++) {
			vector<int> a = dist[i];
			sort(a.begin(), a.end());
			temp += a[0];
		}

		if (chicken_dist > temp)
			chicken_dist = temp;
	} while (next_permutation(v.begin(), v.end()));


	cout << chicken_dist;
	return 0;
}