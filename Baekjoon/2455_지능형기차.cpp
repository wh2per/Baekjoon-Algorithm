// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bj_2455()
{
    int t=4;
    int ans = -1;
    int people=0;
    while(t--){
        int in,out;
        cin >> out >> in;
        people -= out;
        if(people<0)
            people =0;
        people += in;
        if(people>10000)
            people=10000;
        if(people>ans)
            ans = people;
    }
    if(ans==-1)
        cout << 0;
    else
        cout << ans;
    return 0;
}
