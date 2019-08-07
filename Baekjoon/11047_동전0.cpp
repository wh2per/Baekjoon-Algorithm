// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
using namespace std;

int bj_11047()
{
    int n,price;
    cin >> n>> price;
    vector<int> v(n);

    for(int i=n-1; i>=0; --i)
        cin >> v[i];

    int ans=0;
    for(int i=0; i<n; ++i){
        if(v[i]<=price){
            ans += price/v[i];
            price %= v[i];
        }
    }
    cout << ans;
    return 0;
}
