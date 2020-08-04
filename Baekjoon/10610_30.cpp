#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    string input;
    long long sum = 0;
    bool flag = false;

    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        int temp = input[i] - '0';
        if (temp == 0) 
            flag = true;
        sum += temp;
        v.push_back(temp);
    }

    if (!flag || (sum % 3 != 0)) 
        cout << "-1";
    else {
        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i >= 0; i--) 
            cout << v[i];
    }

    cout << endl;
    return 0;
}