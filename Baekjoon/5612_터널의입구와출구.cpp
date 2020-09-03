#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int temp = M;
    int result = M;

    for (int i = 0; i < N; i++){
        int in, out;
        cin >> in >> out;
        
        temp += (in - out);

        if (temp < 0){
            cout << 0 << "\n";
            return 0;
        }
        result = max(result, temp);
    }
    cout << result << "\n";

    return 0;
}
