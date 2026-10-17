#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> h(n + 1);
    vector<long long> r(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < m; i++)
    {
        int p;
        long long x;
        cin >> p >> x;

        r[p] = x;
    }

    vector<long long> dp(n + 1, -1);

    if (k < h[1])
    {
        cout << -1 << endl;
        return 0;
    }

    dp[1] = k - h[1] + r[1];

    for (int i = 2; i <= n; i++)
    {
        long long best = -1;

        if (dp[i - 1] != -1 && dp[i - 1] >= h[i])
        {
            best = max(best, dp[i - 1]);
        }

        if (i >= 3 && dp[i - 2] != -1 && dp[i - 2] >= h[i])
        {
            best = max(best, dp[i - 2]);
        }

        if (best != -1)
        {
            dp[i] = best - h[i] + r[i];
        }
    }

    cout << dp[n] << endl;

    return 0;
}