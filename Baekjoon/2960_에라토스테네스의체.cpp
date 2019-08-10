// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int bj_2960(){
    int n,k;
    cin >> n >> k;
    vector<bool> check(n+1, true);
    check[0] = check[1] = false;

    int count = 0;
    int ans;
    for(int i=2; i<n+1; ++i){
        if(check[i]){
            ++count;
            check[i] = false;
            if(count==k){
                ans = i;
                break;
            }
            bool flag = false;
            for(int j=i; j<n+1; ++j){
                if(j%i==0 && check[j]){
                    ++count;
                    check[j] = false;
                    if(count==k){
                        ans = j;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
    }

    cout << ans;
    return 0;
}
