#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int len = s.size();

    const int MAXN = 10000100;
    vector<bool> is_prime(MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i < MAXN; i++)
    {
        if (is_prime[i])
        {
            for (long long j = i * i; j < MAXN; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    long long low = 1;
    for (int i = 1; i < len; i++)
        low *= 10LL;
    long long high = low * 10;

    vector<long long> primes;
    for (long long i = low; i < high; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }

    for (auto num : primes)
    {
        string t = to_string(num);
        int mp[26];
        fill(mp, mp + 26, -1);
        bool used[10] = {};
        bool ok = true;

        for (int i = 0; i < len; i++)
        {
            int let = s[i] - 'a';
            int d = t[i] - '0';
            if (mp[let] == -1)
            {
                if (used[d])
                {
                    ok = false;
                    break;
                }
                mp[let] = d;
                used[d] = true;
            }
            else if (mp[let] != d)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout << num << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}