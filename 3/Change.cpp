#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long one = 0, ten = 0, hundred = 0;

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;

        long long bills = (a + 999) / 1000;
        long long paid = bills * 1000;
        long long change = paid - a;

        hundred += change / 100;
        change %= 100;

        ten += change / 10;
        change %= 10;

        one += change;
    }

    cout << one << " " << ten << " " << hundred << endl;

    return 0;
}