#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    long long x, y;
    cin >> x >> y;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<long long> preA(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        preA[i] = preA[i - 1] + a[i - 1];
    }

    vector<long long> preB(m + 1, 0);
    vector<long long> preC(m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        preB[i] = preB[i - 1] + b[i - 1];
        long long c = (b[i - 1] + k - 1) / k;
        preC[i] = preC[i - 1] + c;
    }

    long long v = x + y * k;

    long long ans = 0;
    int j = n;

    for (int t = 0; t <= m; t++)
    {
        if (preC[t] > y)
        {
            break;
        }

        long long remaining = v - preB[t];
        if (remaining < 0)
        {
            break;
        }

        while (j > 0 && preA[j] > remaining)
        {
            j--;
        }

        long long total = (long long)t + j;
        if (total > ans)
        {
            ans = total;
        }
    }

    cout << ans << endl;

    return 0;
}