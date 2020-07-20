#include <iostream> 
using namespace std; 

int main(void) {
	long long x, y; 

	while (1) { 
		cin >> x >> y; 
		
		if (x == 0 && y == 0) 
			break; 
		cout << x/y << " " << x%y << " / " << y << "\n"; 
	} 
	return 0;
}

