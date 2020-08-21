#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int> > list;

// 가로 검사  
bool check1(int r, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == num)
            return false;
    }
    return true;
}

// 세로 검사  
bool check2(int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][c] == num)
            return false;
    }
    return true;
}

// 3x3 검사  
bool check3(int r, int c, int num) {
    r = r / 3;
    c = c / 3;
    for (int rr = r * 3; rr < (r * 3) + 3; rr++) {
        for (int cc = c * 3; cc < (c * 3) + 3; cc++) {
            if (sudoku[rr][cc] == num)
                return false;
        }
    }
    return true;
}
bool pass(int x, int y, int num) {
    return (check1(x, num) && check2(y, num) && check3(x, y, num)) ? true : false;
}

void dfs(int index) {
    if (index == list.size()) {                                    // 이미 비어있는 모든 공간을 채운 상태 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j] << ' ';
            cout << '\n';
        }
        exit(0);                                                // 강제 종료 
    }

    for (int i = 1; i <= 9; i++) {                                // 1부터 9까지 삽입해본다. 
        int x = list[index].first;                                // 가로 
        int y = list[index].second;                                // 세로  
        if (pass(x, y, i)) {        // 스도쿠 조건에 만족하면  
            sudoku[x][y] = i;                                    // sudoku 배열에 삽입     
            dfs(index + 1);                                        // 비어있는 다음 스도쿠 배열을 탐색 
            sudoku[x][y] = 0;                                    // 위에서 스도쿠 조건 만족에 실패하여 다시 빠져나옴 
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            sudoku[i][j] = tmp;
            if (tmp == 0)
                list.push_back(make_pair(i, j));
        }
    }

    dfs(0);                                                        // dfs 탐색 
    return 0;
}


