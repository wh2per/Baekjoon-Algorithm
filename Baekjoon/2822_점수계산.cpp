#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> v(8); //{score, idx}

    for (int i = 0; i < 8; i++){
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    int sum = 0;
    vector<int> idx; 
    for (int i = 0; i < 5; i++){
        sum += v[i].first;
        idx.push_back(v[i].second);
    }
    cout << sum << "\n";

    sort(idx.begin(), idx.end());

    for (int i = 0; i < idx.size(); i++)
        cout << idx[i] << " ";

    cout << "\n";
    return 0;
}
