// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp_room(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.second < p2.second)
        return true;
    else if(p1.second==p2.second){
        if(p1.first < p2.first)
            return true;
        else
            return false;
    }else
        return false;
}

int bj_1931()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for(int i=0; i<n; ++i){
        int s,e;
        cin >> s >>e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end(), cmp_room);

    int ans = 1;
    int end = v[0].second;

    for(int i=1; i<n; ++i){
        if(v[i].first<end)
            continue;
        else{
            end = v[i].second;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
