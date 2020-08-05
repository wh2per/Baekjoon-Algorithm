#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
int coord[MAX][MAX];

int main(void){
    int N;
    cin >> N;

    for (int k = 0; k < N; k++){
        int x, y;
        cin >> x >> y;

        for (int i = y + 1; i <= y + 10; i++) {
            for (int j = x + 1; j <= x + 10; j++) {
                coord[i][j] = 1;
            }
        }
    }

    int result = 0;

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            if (coord[i][j])
                result++;
        }
    }

    cout << result << endl;
    return 0;
}

