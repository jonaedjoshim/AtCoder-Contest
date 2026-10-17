#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> add(n + 2);
    vector<vector<int>> remove(n + 2);

    for (int i = 0; i < q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;

        add[l].push_back(x);
        remove[r + 1].push_back(x);
    }

    map<int, int> freq;
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < add[i].size(); j++)
        {
            int x = add[i][j];
            if (freq[x] == 0)
            {
                answer++;
            }
            freq[x]++;
        }

        for (int j = 0; j < remove[i].size(); j++)
        {
            int x = remove[i][j];
            freq[x]--;
            if (freq[x] == 0)
            {
                answer--;
            }
        }

        if (i > 1)
        {
            cout << " ";
        }
        cout << answer;
    }

    cout << endl;

    return 0;
}