#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    map<string, int> mp;
    int next_id = 1;

    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;

        if (mp.find(s) != mp.end())
        {
            cout << mp[s] << '\n';
        }
        else
        {
            mp[s] = next_id;
            cout << next_id << '\n';
            next_id++;
        }
    }

    return 0;
}