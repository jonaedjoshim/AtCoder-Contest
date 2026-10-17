#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int ans = 1;
    int mx = -1;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int mn = 101;
        int mxs = 0;

        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;

            sum += x;
            mn = min(mn, x);
            mxs = max(mxs, x);
        }

        int score = sum - mn - mxs;

        if (score > mx)
        {
            mx = score;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}