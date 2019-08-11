// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int bj_11660(){
    int n,m;
    scanf("%d %d",&n, &m);

    int arr[1025][1025]={{0,}};

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            int num;
            scanf("%d",&num);
            arr[i][j] = arr[i][j-1] + num;
        }
    }

    for(int i=0; i<m; ++i){
        int s1,e1,s2,e2;
        scanf("%d %d %d %d",&s1,&e1,&s2,&e2);
        int ans = 0;
        for(int j=s1; j<=s2; ++j){
            ans += arr[j][e2]-arr[j][e1-1];
        }
        printf("%d\n",ans);
    }
    return 0;
}
