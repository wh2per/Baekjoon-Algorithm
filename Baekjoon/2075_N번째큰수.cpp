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

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n*n; ++i){
        int num;
        scanf("%d",&num);

        if(pq.size()<n)
           pq.push(num);
        else{
            if(pq.top()<num){
                pq.pop();
                pq.push(num);
            }
        }
    }
    printf("%d",pq.top());
    return 0;
}
