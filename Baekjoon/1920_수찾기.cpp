// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
using namespace std;

int num_find[100001];

int bj_1920()
{
    int n,m;
    scanf("%d",&n);

    for(int i=0; i<n; ++i)
        scanf("%d",&num_find[i]);
    sort(num_find,num_find+n);

    scanf("%d",&m);
    for(int i=0; i<m; ++i){
        int num;
        scanf("%d",&num);

        int first = 0;
        int last = n-1;
        int mid = 0;
        bool flag = false;

        while (first <= last){
            mid = (first + last) / 2;
            if (num_find[mid] == num){
                printf("1\n");
                flag = true;
                break;
            }
            else{
                if (num_find[mid] > num)
                    last = mid - 1;
                else
                    first = mid + 1;
            }
        }
        if(!flag)
            printf("0\n");
    }
    return 0;
}
