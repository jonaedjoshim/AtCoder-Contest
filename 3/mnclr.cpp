#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << s[0];
    for (int i = 1; i < s.size(); i++)
    {
        cout << 'o' << s[i];
    }

    return 0;
}