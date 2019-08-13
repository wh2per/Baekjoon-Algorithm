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

    priority_queue<pair<int, int>> pq;

    while(n--){
        int num;
        scanf("%d",&num);
        if(num==0){
            if(pq.empty())
                printf("0\n");
            else{
                printf("%d\n",-pq.top().second);
                pq.pop();
            }
        }else
            pq.push({-abs(num),-num});
    }
    return 0;
}
