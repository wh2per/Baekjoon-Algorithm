#include <iostream>
using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    while (1)
    {
        cnt++;
        if (N == 1)
        {
            cout << cnt;
            break;
        }
        if (N % 2 == 0)
        {
            N = N / 2;
        }
        else
        {
            N = 3 * N + 1;

        }
    }
    return 0;
}