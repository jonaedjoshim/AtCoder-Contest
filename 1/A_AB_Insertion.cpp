#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int i;
            char c;
            cin >> i >> c;
            s[i - 1] = c;
        }
        else
        {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            int a_count = 0;
            int b_count = 0;
            int ok = 1;

            for (int j = l; j <= r; j++)
            {
                if (s[j] == 'A')
                {
                    a_count++;
                }
                else
                {
                    b_count++;
                }

                if (b_count > a_count)
                {
                    ok = 0;
                    break;
                }
            }

            if (ok == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}