#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> match_positions;

    for (int i = 0; i + m <= n; i++)
    {
        int flag = 1;

        for (int j = 0; j < m; j++)
        {
            if (s[i + j] != t[j])
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            match_positions.push_back(i);
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int min_start = l - 1;
        int max_start = r - m;

        if (min_start > max_start)
        {
            cout << "No" << endl;
            continue;
        }

        auto it = lower_bound(match_positions.begin(), match_positions.end(), min_start);

        if (it != match_positions.end() && *it <= max_start)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}