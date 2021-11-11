#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

struct Pos {
    int x, y;
};

const int MAX = 2000000000;
Pos points[100001];
Pos candidates[100001];
int n;
int c;

bool compX(Pos& a, Pos& b) {
    if (a.x < b.x)
        return true;
    else
        return false;
}

bool compY(Pos& a, Pos& b) {
    if (a.y < b.y)
        return true;
    else
        return false;
}

int dist(int a, int b) {
    return (points[a].x - points[b].x) * (points[a].x - points[b].x) + (points[a].y - points[b].y) * (points[a].y - points[b].y);
}

int solve(int low, int high) {
    if (low == high)
        return MAX;

    if (low + 1 >= high)
        return dist(low, high);

    int dmin = dist(low, high);
    int temp = 0;

    int mid = (low + high) >> 1;

    // 왼쪽 영역
    temp = solve(low, mid);
    if (temp < dmin) {
        dmin = temp;
    }

    // 오른쪽 영역
    temp = solve(mid + 1, high);
    if (temp < dmin) {
        dmin = temp;
    }

    // 중간 영역
    int middleX = points[mid].x;
    c = 0;

    for (int i = mid; i >= low; --i) {
        int distX = middleX - points[i].x;
        if (dmin <= distX * distX)
            break;
        candidates[c++] = { points[i].x, points[i].y };
    }

    for (int i = mid + 1; i <= high; ++i) {
        int distX = middleX - points[i].x;
        if (dmin <= distX * distX)
            break;
        candidates[c++] = { points[i].x, points[i].y };
    }

    if (c == 0)
        return dmin;

    sort(candidates, candidates + c, compY);

    for (int i = 0; i < c; ++i) {
        int ix = candidates[i].x;
        int iy = candidates[i].y;

        for (int j = i + 1; j < c; ++j) {
            int jx = candidates[j].x;
            int jy = candidates[j].y;

            if ((iy - jy) * (iy - jy) >= dmin)
                break;
            if ((ix - jx) * (ix - jx) >= dmin)
                continue;

            int ans = (iy - jy) * (iy - jy) + (ix - jx) * (ix - jx);
            if (dmin > ans)
                dmin = ans;
        }
    }

    return dmin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        points[i] = { x,y };
    }

    sort(points, points + n, compX);

    cout << solve(0, n - 1);

    return 0;
}