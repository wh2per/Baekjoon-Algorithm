#include <iostream>
using namespace std;

int main() {
    double a, b, n, cnt;
    cin >> n;
    cnt = n;
    while (1)
    {
        cin >> a;
        if (a == 999)break;
        printf("%.2f\n", a - cnt);
        cnt = a;
    }

    return 0;
}
