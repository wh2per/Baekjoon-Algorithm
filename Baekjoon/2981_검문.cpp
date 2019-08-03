// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int bj_2981()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int end = v.back() - v.front();
    vector<int> a;
    for(int i=2; i<sqrt(end); ++i){
        if(end%i==0){
            a.push_back(i);
            a.push_back(end/i);
        }
    }
    if(sqrt(end)*sqrt(end)==end)
        a.push_back(sqrt(end));
    a.push_back(end);
    sort(a.begin(), a.end());
    for(int i=0; i<a.size(); ++i){
        int left = v[0]%a[i];
        int j;
        for(j=1; j<n; ++j){
            if(v[j]%a[i]!=left)
                break;
        }
        if(j==n)
            cout << a[i] << " ";
    }

    return 0;
}
