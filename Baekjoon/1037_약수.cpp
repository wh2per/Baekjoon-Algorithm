// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_1037()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());
    cout << v.front() * v.back();
    return 0;
}
