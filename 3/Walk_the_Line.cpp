#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    long long limit;
    cin >> n >> s >> limit;

    vector<long long> a(n - 1);
    for (auto &x : a)
        cin >> x;

    vector<long long> pos(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        pos[i] = pos[i - 1] + a[i - 2];
    }

    int ans = 1;
    for (int left = 1; left <= s; left++)
    {
        for (int right = s; right <= n; right++)
        {
            long long len = pos[right] - pos[left];
            long long dl = pos[s] - pos[left];
            long long dr = pos[right] - pos[s];
            long long cost = 2LL * len - max(dl, dr);
            if (cost <= limit)
            {
                ans = max(ans, right - left + 1);
            }
        }
    }

    cout << ans << endl;
}