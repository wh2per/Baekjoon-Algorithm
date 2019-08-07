// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int bj_11399()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());
    int ans = 0;

    for(int i=0; i<n; ++i){
        int sum =0;
        for(int j=0; j<i+1; ++j)
            sum += v[j];
        ans += sum;
    }

    cout << ans;
    return 0;
}
