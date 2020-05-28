#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> pw;

	while (n--) {
		string s, a;
		cin >> s >> a;

		pw.insert({ s,a });
	}

	while (m--) {
		string s;
		cin >> s;
		cout << pw[s] << "\n";
	}
	return 0;
}