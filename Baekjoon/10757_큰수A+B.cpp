#include <iostream>
#include <string>
using namespace std;

int bj_10757() {
	string s1, s2, s3;
	cin >> s1 >> s2;

	int carry = 0;
	int oper1 = 0;
	int oper2 = 0;
	int oper3 = 0;

	int idx1 = s1.length()-1;
	int idx2 = s2.length()-1;

	string temp = "";
	if (idx1 > idx2) {
		for (int i = 0; i < idx1 - idx2; i++)
			temp += "0";
		s2 = temp + s2;
	}
	else {
		for (int i = 0; i < idx2 - idx1; i++)
			temp += "0";
		s1 = temp + s1;
	}

	idx1 = s1.length() - 1;
	idx2 = s2.length() - 1;

	while (idx1>=0) {
		oper1 = s1[idx1--] - '0';
		oper2 = s2[idx2--] - '0';

		oper3 = oper1 + oper2 + carry;
		if (oper3 > 9) {
			carry = 1;
			oper3 -= 10;
			s3 += to_string(oper3);
		}
		else {
			carry = 0;
			s3 += to_string(oper3);
		}
	}

	if (carry == 1)
		s3 += "1";

	for (int i = s3.length() - 1; i >= 0; --i)
		cout << s3[i];

	return 0;
}