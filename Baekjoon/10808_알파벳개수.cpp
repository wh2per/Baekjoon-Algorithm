#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int c[26];

int main()
{
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
        c[str[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        cout << c[i] << " ";


    return 0;
}


