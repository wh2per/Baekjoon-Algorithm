#include<iostream>
using namespace std;

long long a[1500050];
int INF = 1000000;

void fibonacci() {      // 피사노 주기를 통해 1,000,000으로 나눈 피보나치 수열의 반복되는 주기는 1,500,000이란 것을 알 수 있음
    a[0] = 0;
    a[1] = 1;
    for (int i = 0; i < 1500000; i++) {
        a[i + 2] = (a[i + 1] + a[i]) % INF;
    }
}

int main() {
    long long n;
    cin >> n;
    fibonacci();
    cout << a[n % 1500000] << "\n";

}