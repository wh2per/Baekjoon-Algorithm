#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;
//머지되면서 인덱스위치를 변경시켜 기록
int arr[500001];
int arr2[500001];
//출력할 배열
int base[500001];
//데이터
int s[500001];
//머지용 임시데이터
int v[500001];

void merge(int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    while (i <= middle && j <= n) {
        if (s[i] > s[j]) {
            v[k] = s[i];
            arr2[k] = arr[i];
            i++;
        }
        else {
            v[k] = s[j];
            arr2[k] = arr[j];
            base[arr[j]] -= (middle + 1 - i);
            j++;
        }
        k++;
    }
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            v[k] = s[t];
            arr2[k] = arr[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= middle; t++) {
            v[k] = s[t];
            arr2[k] = arr[t];
            k++;
        }
    }
    for (int t = m; t <= n; t++) {
        s[t] = v[t];
        arr[t] = arr2[t];
    }
}

void mergeSort(int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(m, middle);
        mergeSort(middle + 1, n);
        merge(m, middle, n);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = i;
        base[i] = i + 1;
        s[i] = tmp;
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << base[i] << '\n';
    }
    return 0;
}