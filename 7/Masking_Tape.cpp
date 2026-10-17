#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> tile(n + 1, 0);
    vector<char> color(n + 1, 'a');
    vector<int> last_change(n + 1, 0);

    int last_type2_time = 0;
    char last_type2_color = 'a';

    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;

            if (tile[x] == 0)
            {
                char effective;
                if (last_type2_time > last_change[x])
                {
                    effective = last_type2_color;
                }
                else
                {
                    effective = color[x];
                }

                color[x] = effective;
                tile[x] = 1;
            }
            else
            {
                tile[x] = 0;
                last_change[x] = i;
            }
        }
        else
        {
            char c;
            cin >> c;

            last_type2_time = i;
            last_type2_color = c;
        }
    }

    string ans = "";
    for (int i = 1; i <= n; i++)
    {
        if (tile[i] == 1)
        {
            ans += color[i];
        }
        else
        {
            if (last_type2_time > last_change[i])
            {
                ans += last_type2_color;
            }
            else
            {
                ans += color[i];
            }
        }
    }

    cout << ans << endl;

    return 0;
}