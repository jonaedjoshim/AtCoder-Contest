#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> freq(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    int highest = 0;

    for (int i = 1; i <= k; i++)
    {
        highest = max(highest, freq[i]);
    }

    int res = 0;

    for (int i = 1; i <= k; i++)
    {
        if (freq[i] + 1 >= highest)
        {
            res++;
        }
    }

    cout << res << endl;

    return 0;
}