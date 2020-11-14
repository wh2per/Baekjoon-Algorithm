#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
int recommend[MAX];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    //{시간, 사진}
    vector<pair<int, int>> v(N, { 0, 0 });
    int rec;
    cin >> rec;

    for (int i = 0; i < rec; i++)
    {
        int num;
        cin >> num;
        recommend[num]++;

        bool replace = true;
        for (int j = 0; j < N; j++)
        {
            //액자가 비어있는 경우
            if (v[j].second == 0)
            {
                v[j].second = num;
                v[j].first = i;
                replace = false;
                break;
            }
            //이미 액자에 있는 경우
            else if (v[j].second == num)
            {
                replace = false;
                break;
            }
        }

        //사진을 바꿔야하는 경우
        if (replace)
        {
            int idx = 0;
            for (int j = 1; j < N; j++)
            {
                //제일 추천 수가 낮은 사진들이 여러개인 경우
                if (recommend[v[j].second] == recommend[v[idx].second])
                {
                    //가장 오래된
                    if (v[j].first < v[idx].first)
                        idx = j;
                }
                //추천수가 낮은 순서
                else if (recommend[v[j].second] < recommend[v[idx].second])
                    idx = j;
            }
            recommend[v[idx].second] = 0; //바꿔쳐지면 추천수 초기화
            v[idx].first = i;
            v[idx].second = num;
        }
    }

    vector<int> picture;

    for (int i = 0; i < N; i++)
        picture.push_back(v[i].second);

    sort(picture.begin(), picture.end());
    for (int i = 0; i < N; i++)
        cout << picture[i] << " ";
    cout << "\n";
    
    return 0;

}
