#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<long long, long long>> pts(n);
        for (int i = 0; i < n; i++)
        {
            cin >> pts[i].first >> pts[i].second;
        }

        sort(pts.begin(), pts.end(), [](pair<long long, long long> p, pair<long long, long long> q)
             {
                 long long cp = p.first * q.second - p.second * q.first;

                 int hp = 0;
                 if (p.second < 0 || (p.second == 0 && p.first < 0))
                 {
                     hp = 1;
                 }
                 int hq = 0;
                 if (q.second < 0 || (q.second == 0 && q.first < 0))
                 {
                     hq = 1;
                 }

                 if (hp != hq)
                 {
                     return hp < hq;
                 }
                 return cp > 0; });

        int best = 1;
        int right = 0;

        for (int left = 0; left < n; left++)
        {
            if (right < left + 1)
            {
                right = left + 1;
            }

            while (right < left + n)
            {
                int idx = right % n;
                long long cp = pts[left].first * pts[idx].second - pts[left].second * pts[idx].first;

                if (cp > 0)
                {
                    right++;
                }
                else
                {
                    break;
                }
            }

            int cnt = right - left;
            if (cnt > best)
            {
                best = cnt;
            }
        }

        cout << best << '\n';
    }

    return 0;
}