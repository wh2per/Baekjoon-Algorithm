// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
using namespace std;

int bj_5086()
{
    while(1){
        int a,b;
        cin >> a >> b;

        if(a==0 && b==0)
            break;

        if(a>b){
            if(a % b==0)
                cout << "multiple\n";
            else
                cout << "neither\n";
        }else{
            if(b % a==0)
                cout << "factor\n";
            else
                cout << "neither\n";
        }
    }
    return 0;
}
