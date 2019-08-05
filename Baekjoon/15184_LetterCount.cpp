// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int bj_15184()
{
    string str,r;
    getline(cin, str);
    getline(cin, r);

    vector<int> v(26,0);

    for(auto a : str){
        if(isalpha(a)){
            char c = tolower(a);
            ++v[c-'a'];
        }
    }

    for(int i=0; i<26; ++i){
        char c = i+'A';
        cout << c << " | ";
        for(int j=0; j<v[i]; ++j)
            cout << "*";
        cout << "\n";
    }
    return 0;
}
