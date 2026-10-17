#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int each = m / n;
    int remaining = m % n;

    for (int i = 1; i <= n; i++)
    {
        if (i <= remaining)
        {
            cout << each + 1 << endl;
        }
        else
        {
            cout << each << endl;
        }
    }

    return 0;
}