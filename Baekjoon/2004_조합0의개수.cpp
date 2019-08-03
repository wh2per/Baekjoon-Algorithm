// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int bj_2004()
{
    int n,m;
    cin >> n >> m;

    if(n-m < m)
        m = n-m;

    int ans1 = 0;
    int ans2 = 0;

    int start=n,end=n-m;
    int a=0,b=0,c=0;
    long long div = 5;

    while(start>=div){
        a += start/div;
        div *= 5;
    }

    div = 5;
    while(end>=div){
        b += end/div;
        div *= 5;
    }

    div = 5;
    int left = m;
    while(left>=div){
        c += left/div;
        div *= 5;
    }

    ans1 = a - b - c;

    int d=0,e=0,f=0;
    div = 2;

    while(start>=div){
        d += start/div;
        div *= 2;
    }

    div = 2;
    while(end>=div){
        e += end/div;
        div *= 2;
    }

    div = 2;
    while(left>=div){
        f += left/div;
        div *= 2;
    }

    ans2 = d - e -f;
    if(ans2<0)
        ans2 = 0;

    if(ans1<=ans2)
        cout << ans1;
    else
        cout << ans2;
    return 0;
}
