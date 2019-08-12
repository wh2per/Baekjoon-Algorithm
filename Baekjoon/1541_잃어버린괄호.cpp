// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    vector<int> num;
    vector<char> oper;

    string temp="";
    for(auto a : s){
        if(!isdigit(a)){
            num.push_back(stoi(temp));
            oper.push_back(a);
            temp="";
        }else
            temp += a;
    }
    num.push_back(stoi(temp));

    int ans = 0;
    bool flag = false;

    for(int i=0; i<oper.size(); ++i){
        if(flag)
            ans -= num[i];
        else
            ans += num[i];

        if(oper[i]=='-')
            flag = true;
    }
    if(flag)
        ans -= num[num.size()-1];
    else
        ans += num[num.size()-1];
    cout << ans;
    return 0;
}
