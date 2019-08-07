// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bj_2167()
{
    int n,m;
    cin >> n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            cin >> v[i][j];
    }

    int t;
    cin >> t;
    while(t--){
        int s1,s2,e1,e2;
        cin >> s1 >> e1 >> s2 >> e2;

        int ans=0;
        for(int i=s1-1; i<s2; ++i){
            for(int j=e1-1; j<e2; ++j)
                ans += v[i][j];
        }
        cout << ans << endl;
    }

    return 0;
}
