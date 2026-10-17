#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (t[i] != '*' && t[i] != s[i])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}