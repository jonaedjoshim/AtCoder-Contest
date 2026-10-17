#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    multiset<pair<long long, int>> s;

    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert({a[i], i});
        ans += a[i];
    }

    while (q--)
    {
        int t, r;
        long long x;
        cin >> t >> x >> r;

        pair<long long, int> cur;

        if (t == 1)
        {
            cur = *s.rbegin();
        }
        else
        {
            cur = *s.begin();
        }

        long long old = cur.first;
        int id = cur.second;

        s.erase(cur);

        ans -= old;
        ans += x;

        if (r == 0)
        {
            a[id] = x;
            s.insert({x, id});
        }
        else
        {
            ans -= x;
            ans += old;
            s.insert({old, id});
        }
    }

    cout << ans << endl;

    return 0;
}