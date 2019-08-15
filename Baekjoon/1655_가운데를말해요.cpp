// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    priority_queue<int, vector<int>> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;

    for(int i=0; i<n; ++i){
        int num;
        scanf("%d",&num);
        if(maxpq.empty() && minpq.empty())
            maxpq.push(num);
        else if(maxpq.size() == minpq.size())
            maxpq.push(num);
        else
            minpq.push(num);

        if(!maxpq.empty() && !minpq.empty() && maxpq.top()>minpq.top()){
            int temp = maxpq.top();
            maxpq.pop();
            maxpq.push(minpq.top());
            minpq.pop();
            minpq.push(temp);
        }
        printf("%d\n",maxpq.top());
    }
    return 0;
}
