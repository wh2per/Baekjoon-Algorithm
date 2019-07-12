#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int bj_1912() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    for (int i=0; i<n; i++) {
        d[i] = a[i];
        if (i == 0) continue;
        d[i] = max(d[i],d[i-1] + a[i]);
    }
    cout << *max_element(d.begin(),d.end()) << '\n';
    return 0;
}