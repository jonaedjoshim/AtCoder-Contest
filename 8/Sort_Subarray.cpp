#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), sorted_a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    sort(sorted_a.begin(), sorted_a.end());

    if (a == sorted_a)
    {
        cout << "Yes" << endl;
        return 0;
    }

    int left = 0, right = n - 1;

    while (left < n && a[left] == sorted_a[left])
    {
        left++;
    }

    while (right >= 0 && a[right] == sorted_a[right])
    {
        right--;
    }

    if (right - left + 1 <= k)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}