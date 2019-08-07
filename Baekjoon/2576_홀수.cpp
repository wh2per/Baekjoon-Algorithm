// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bj_2576()
{
    vector<int> v(7);
    for(int i=0; i<7; ++i)
        cin >> v[i];

    int ans1 = 0;
    int ans2 = 100;
    for(auto a : v){
        if(a%2!=0){
            ans1 += a;
            if(ans2 > a)
                ans2 = a;
        }
    }
    if(ans2==100)
        cout << -1;
    else
        cout << ans1 << "\n" << ans2;
    return 0;
}
