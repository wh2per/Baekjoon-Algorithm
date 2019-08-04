// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int bj_17294()
{
    string s;
    cin >> s;

    vector<int> v;

    for(auto a : s)
        v.push_back(a-'0');

    if(v.size() < 3)
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    else{
        int diff = v[1] - v[0];
        int i=1;
        for(i=2; i<v.size(); ++i){
            if(v[i]-v[i-1] != diff)
                break;
        }
        if(i==v.size())
            cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
        else
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
    }
    return 0;
}
