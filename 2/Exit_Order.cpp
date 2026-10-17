#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int flag = 1;
    vector<int> first(n + 1);

    for (int i = 0; i < n; i++)
    {
        first[arr[i]] = i;
    }

    for (int start = 1; start <= n; start += 10)
    {
        int end = min(start + 9, n);

        int mn = n + 1, mx = -1;
        for (int seat = start; seat <= end; seat++)
        {
            mn = min(mn, first[seat]);
            mx = max(mx, first[seat]);
        }

        for (int seat = start; seat <= end; seat++)
        {
            int pos = first[seat];
            if (pos < mn || pos > mx)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 0)
        {
            break;
        }

        int next_start = start + 10;
        if (next_start <= n)
        {
            int next_end = min(next_start + 9, n);
            int next_mn = n + 1;
            for (int seat = next_start; seat <= next_end; seat++)
            {
                next_mn = min(next_mn, first[seat]);
            }

            if (mx > next_mn)
            {
                flag = 0;
                break;
            }
        }
    }

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}