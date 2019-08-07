// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_key(pair<int, int> &a, pair<int,int> &b){
    if(a.first<b.first)
        return true;
    else if(a.first==b.first){
        if(a.second < b.second)
            return true;
        else
            return false;
    }else
        return false;
}

int bj_11724()
{
    int n,m;
    vector<set<int>> v;
    vector<pair<int, int>> keys;
    
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int s,e;
        cin >> s >> e;

        if(s<e)
            keys.push_back({s,e});
        else
            keys.push_back({e,s});
    }

    sort(keys.begin(), keys.end(), cmp_key);

    for(auto a : keys){
        int s = a.first;
        int e = a.second;

        bool check = false;
        for(int j=0; j<v.size(); ++j){
            if(v[j].count(s)!=0){
                v[j].insert(e);
                check = true;
                break;
            }else if(v[j].count(e)!=0){
                v[j].insert(s);
                check = true;
                break;
            }
        }
        if(!check){
            set<int> newline;
            newline.insert(s);
            newline.insert(e);
            v.push_back(newline);
        }
    }

    int ans=v.size();
    for(int i=1; i<=n; ++i){
        bool check = false;
        for(int j=0; j<v.size(); ++j){
            if(v[j].count(i)!=0){
                check = true;
                break;
            }
        }
        if(!check)
            ++ans;
    }

    cout << ans;
    return 0;
}
