#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long cur = 0;
    long long ans = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        x--;

        cur = max(x, cur + x);
        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}