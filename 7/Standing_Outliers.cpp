#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    vector<long long> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int flag = 1;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            long long diff = x[i] - x[j];
            if (diff < 0)
            {
                diff = -diff;
            }

            if (diff < d)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return 0;
}