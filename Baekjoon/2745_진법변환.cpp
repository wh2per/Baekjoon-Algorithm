// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int bj_2745()
{
    vector<char> v;
    string n;
    int b;
    cin >> n>> b;

    for(auto a : n)
        v.push_back(a);

    int ans = 0;
    int pos = 0;
    for(int i=v.size()-1; i>=0; --i){
        char c = v[i];
        int num;
        if(isalpha(c))
            num = c-'A'+10;
        else
            num = c-'0';
        ans += num*pow(b,pos);
        ++pos;
    }
    cout << ans;
    return 0;
}
