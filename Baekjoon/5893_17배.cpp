#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	// B=N일 때, 17N = B + 16B(=A)
	string a,b;
	cin >> b;
	a = b+"0000";

	bool carry = false;
	int i;

	for (i = b.size()-1; i >=0; --i) {
		int c = a[i+4] - '0' + b[i] - '0' + carry;
		if (c > 1) {
			c -= 2;
			carry = true;
		}
		else 
			carry = false;
		a[i+4] = c + '0';
	}
	// B의 범위를 넘어가는 A의 4자리 계산
	for (int i = 3; i >= 0; --i) {
		int c = a[i] - '0' + carry;
		if (c == 2) {
			c = 0;
			carry = true;
		}
		else carry = false;
		a[i] = c + '0';
	}
	// 마지막 자리에서 carry 발생시 처리
	if (carry)
		a = "1" + a;

	// 다시 제일 오른쪽 자리를 LSB로 맞추고 출력
	cout << a << endl;
}

