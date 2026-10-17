#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    cin >> n >> q;

    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<long long> pref_a(n + 1, 0);
    vector<long long> pref_b(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        pref_a[i] = pref_a[i - 1] + a[i];
        pref_b[i] = pref_b[i - 1] + pref_a[i];
    }

    while (q--)
    {
        long long l, r;
        cin >> l >> r;

        auto get_val = [&](long long x) {
            if (x <= 0) return 0LL;

            long long low = 1, high = n;
            long long k = n;

            while (low <= high)
            {
                long long mid = low + (high - low) / 2;
                if (mid * (mid + 1) / 2 >= x)
                {
                    k = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            long long prev_total = (k - 1) * k / 2;
            long long rem = x - prev_total;

            long long ans = pref_b[k - 1];
            ans += pref_a[rem];

            return ans;
        };

        long long ans = get_val(r) - get_val(l - 1);
        cout << ans << '\n';
    }

    return 0;
}

