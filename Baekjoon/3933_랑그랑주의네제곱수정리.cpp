#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;

	while (1) {
		cin >> num;
		if (num == 0)
			break;

		int n = 0;
		int end = (int)sqrt(num);

		for (int i = 1; i <= end; i++) {
			if (i * i == num) {
				n++;
				continue;
			}
			for (int j = i; j <= end; j++) {
				if (i * i + j * j == num) {
					n++;
					break;
				}
				else if (i * i + j * j > num)
					break;

				for (int k = j; k <= end; k++) {
					if (i * i + j * j + k * k == num) {
						n++;
						break;
					}
					else if (i * i + j * j + k * k > num)
						break;

					for (int l = k; l <= end; l++) {
						if (i * i + j * j + k * k + l * l == num) {
							n++;
							break;
						}
						else if (i * i + j * j + k * k + l * l > num)
							break;
					}
				}
			}
		}

		cout << n << '\n';
	}

	return 0;
}
