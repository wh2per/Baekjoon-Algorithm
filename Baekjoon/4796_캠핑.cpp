#include<iostream>
using namespace std;

int main(){
	int L, P, V, ans, cnt = 1;

	while (true){
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		else{
			if (P < V){
				int one, two;
				one = V / P * L;
				two = V % P > L ? L : V % P;
				ans = one + two;
				cout << "Case " << cnt++ << ": " << ans << endl;
			}
		}
	}
	return 0;
}