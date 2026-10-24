#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> free_go(n + 1, -1);

    for (int u = 1; u <= n; u++)
    {
        if (adj[u].size() > 0)
        {
            int smallest = adj[u][0];

            for (int idx = 1; idx < (int)adj[u].size(); idx++)
            {
                if (adj[u][idx] < smallest)
                {
                    smallest = adj[u][idx];
                }
            }

            free_go[u] = smallest;
        }
    }

    vector<int> dist(n + 1, -1);
    deque<int> dq;

    dist[s] = 0;
    dq.push_front(s);

    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();

        if (free_go[u] != -1)
        {
            int v = free_go[u];
            if (dist[v] == -1 || dist[v] > dist[u])
            {
                dist[v] = dist[u];
                dq.push_front(v);
            }
        }

        for (int idx = 0; idx < (int)adj[u].size(); idx++)
        {
            int v = adj[u][idx];

            if (v == free_go[u])
            {
                continue;
            }

            if (dist[v] == -1 || dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                dq.push_back(v);
            }
        }
    }

    if (dist[t] == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dist[t] << '\n';
    }

    return 0;
}