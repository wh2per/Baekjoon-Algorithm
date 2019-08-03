// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
using namespace std;

bool so_in[10000001];
int so_in_p[10000001];

int bj_11653()
{
    int count = 0;

    for(int i=2; i<=10000000; ++i){
	   if(so_in[i] == false){
            // 추가
            so_in_p[count++] = i;
            // i의 배수 지우기
            for(int j=i+i; j<=10000000; j+=i){
                so_in[j] = true;
            }
	   }
    }

    int n;
    cin >> n;

    while(n!=1){
        int i=0;
        for(i=0; i<=10000000; ++i){
            if(n%so_in_p[i]==0)
                break;
        }
        n /= so_in_p[i];
        cout << so_in_p[i] << "\n";
    }
    return 0;
}
