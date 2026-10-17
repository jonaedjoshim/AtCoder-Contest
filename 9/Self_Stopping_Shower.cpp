#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k, t;
    cin >> n >> k >> t;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    long long current_end = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_end >= t)
        {
            break;
        }

        if (a[i] > current_end)
        {
            long long gap = a[i] - current_end;
            long long need = (gap + k - 1) / k;
            ans += need;
            current_end += need * k;
        }

        if (current_end > a[i] + k)
        {
            continue;
        }

        current_end = a[i] + k;
    }

    if (current_end < t)
    {
        long long gap = t - current_end;
        long long need = (gap + k - 1) / k;
        ans += need;
    }

    cout << ans << '\n';

    return 0;
}