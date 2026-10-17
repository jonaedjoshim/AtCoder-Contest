#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<int> votes(n, 0);

    for (int j = 0; j < m; j++)
    {
        string t;
        cin >> t;

        int exact_idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t)
            {
                exact_idx = i;
                break;
            }
        }

        if (exact_idx != -1)
        {
            votes[exact_idx]++;
            continue;
        }

        int match_idx = -1;
        int match_count = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i].size() != t.size())
            {
                continue;
            }

            int diff = 0;
            for (int k = 0; k < t.size(); k++)
            {
                if (s[i][k] != t[k])
                {
                    diff++;
                }
            }

            if (diff == 1)
            {
                match_idx = i;
                match_count++;
            }
        }

        if (match_count == 1)
        {
            votes[match_idx]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << votes[i] << '\n';
    }

    return 0;
}