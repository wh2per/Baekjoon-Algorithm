// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int bj_3047(){
    vector<int> v(3);
    for(int i=0; i<3; ++i)
        cin >>v[i];
    sort(v.begin(), v.end());
    string s;
    cin >> s;

    for(auto a : s){
        if(a == 'A')
            cout << v[0];
        else if(a=='B')
            cout << v[1];
        else
            cout << v[2];
        cout << " ";
    }
    return 0;
}
