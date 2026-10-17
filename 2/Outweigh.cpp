#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    __int128 sum = 0;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        sum += (__int128)a[i] * (a[i] - b[i]);

        if (a[i] > b[i] && idx == -1)
        {
            idx = i;
        }
    }

    if (sum > 0)
    {
        cout << "Yes" << endl;

        for (int i = 0; i < n; i++)
        {
            cout << a[i];

            if (i < n - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
    else if (idx != -1)
    {
        cout << "Yes" << endl;

        for (int i = 0; i < n; i++)
        {
            if (i == idx)
            {
                cout << 1000000000000000000LL;
            }
            else
            {
                cout << 1;
            }

            if (i < n - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}