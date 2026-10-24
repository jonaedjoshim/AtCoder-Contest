#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            total++;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        int low = min(a[i], a[i + 1]);
        int high = max(a[i], a[i + 1]);

        if (low < k && k < high)
        {
            total++;
        }
    }

    cout << total << '\n';

    return 0;
}