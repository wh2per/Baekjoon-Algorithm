#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 

int main(void) { 
	vector<int> arr(3); 
	
	for (int i = 0; i < 3; i++)
		cin >> arr[i]; 
	
	sort(arr.begin(), arr.end()); 
	
	int d1, d2; 
	d1 = arr[1] - arr[0]; 
	d2 = arr[2] - arr[1]; 
	int ans; 
	
	if (d1 == d2) 
		ans = arr[2] + d1; 
	else { 
		if (d1 > d2) { 
			ans = arr[0] + d2; 
		} else {
			ans = arr[1] + d1;
		} 
	} 
	cout << ans; 

	return 0;
}

