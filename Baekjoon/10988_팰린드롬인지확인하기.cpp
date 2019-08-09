// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int bj_10988()
{
    string str;
    cin >> str;

    int len = str.length();
    bool flag = true;

    int s=0,e=len-1;
    while(flag && s<len/2){
        if(str[s]!=str[e]){
            flag = false;
            break;
        }else{
            ++s;
            --e;
        }
    }

    if(flag)
        cout << 1;
    else
        cout << 0;
    return 0;
}
