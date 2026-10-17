#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> seen;
    seen[0] = 1;

    int total = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        total = (total + a[i]) % k;

        if (seen.find(total) != seen.end())
        {
            ans++;
            seen.clear();
            seen[0] = 1;
            total = 0;
        }
        else
        {
            seen[total] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}