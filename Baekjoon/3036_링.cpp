// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
using namespace std;

int bj_3036()
{
    int n, first;
    cin >> n;

    cin >> first;
    for(int i=1; i<n; ++i){
        int a=1,b=1,num1;
        num1 = first;
        int num2;
        cin >> num2;

        while(num1 < num2 || num1 % num2 != 0){
            ++a;
            num1 = first*a;
        }
        b = num1 / num2;
        cout << b << "/"<<a<<"\n";
    }
    return 0;
}
