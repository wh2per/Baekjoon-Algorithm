// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> rope(n);

    for(int i=0; i<n; ++i)
        cin >> rope[i];

    sort(rope.begin(), rope.end(), greater<>());

    int ans = 0;
    for(int i = 0; i<n; ++i)
        ans = max(ans, rope[i]*(i+1));

    cout << ans;
    return 0;
}
