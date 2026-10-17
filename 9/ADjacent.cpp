#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char s[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> s[i][j];
        }
    }

    int r1 = -1, c1 = -1, r2 = -1, c2 = -1;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (s[i][j] == 'A')
            {
                r1 = i;
                c1 = j;
            }
            if (s[i][j] == 'D')
            {
                r2 = i;
                c2 = j;
            }
        }
    }

    int diff = abs(r1 - r2) + abs(c1 - c2);

    if (diff == 1)
    {
        cout << "Yes" << '\n';
    }
    else
    {
        cout << "No" << '\n';
    }

    return 0;
}