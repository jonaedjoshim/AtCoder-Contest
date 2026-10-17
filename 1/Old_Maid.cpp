#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> freq(101, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    int sum = 0;

    for (int i = 1; i < 101; i++)
    {
        if (freq[i] % 2 == 1)
        {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}