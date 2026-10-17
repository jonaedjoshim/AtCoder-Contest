#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    vector<int> last_time(n + 1, -1);
    for (int i = 0; i < q; i++)
    {
        last_time[queries[i]] = i;
    }

    vector<int> ans;
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (last_time[arr[i]] == -1)
        {
            ans.push_back(arr[i]);
        }
        else
        {
            temp.push_back(arr[i]);
        }
    }

    vector<pair<int, int>> moved;
    for (int i = 0; i < temp.size(); i++)
    {
        moved.push_back({last_time[temp[i]], temp[i]});
    }

    sort(moved.begin(), moved.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    for (int i = 0; i < moved.size(); i++)
    {
        cout << moved[i].second;
        if (i < moved.size() - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}