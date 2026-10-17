#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p;
vector<int> minVal, minPos, maxVal, maxPos;

void build(int node, int l, int r)
{
    if (l == r)
    {
        minVal[node] = maxVal[node] = p[l];
        minPos[node] = maxPos[node] = l;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);

    if (minVal[2 * node] < minVal[2 * node + 1])
    {
        minVal[node] = minVal[2 * node];
        minPos[node] = minPos[2 * node];
    }
    else
    {
        minVal[node] = minVal[2 * node + 1];
        minPos[node] = minPos[2 * node + 1];
    }

    if (maxVal[2 * node] > maxVal[2 * node + 1])
    {
        maxVal[node] = maxVal[2 * node];
        maxPos[node] = maxPos[2 * node];
    }
    else
    {
        maxVal[node] = maxVal[2 * node + 1];
        maxPos[node] = maxPos[2 * node + 1];
    }
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r)
    {
        minVal[node] = maxVal[node] = val;
        minPos[node] = maxPos[node] = idx;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
    {
        update(2 * node, l, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, r, idx, val);
    }

    if (minVal[2 * node] < minVal[2 * node + 1])
    {
        minVal[node] = minVal[2 * node];
        minPos[node] = minPos[2 * node];
    }
    else
    {
        minVal[node] = minVal[2 * node + 1];
        minPos[node] = minPos[2 * node + 1];
    }

    if (maxVal[2 * node] > maxVal[2 * node + 1])
    {
        maxVal[node] = maxVal[2 * node];
        maxPos[node] = maxPos[2 * node];
    }
    else
    {
        maxVal[node] = maxVal[2 * node + 1];
        maxPos[node] = maxPos[2 * node + 1];
    }
}

void query(int node, int l, int r, int ql, int qr, int &mnVal, int &mnPos, int &mxVal, int &mxPos)
{
    if (qr < l || r < ql)
    {
        mnVal = INT_MAX;
        mxVal = INT_MIN;
        return;
    }
    if (ql <= l && r <= qr)
    {
        mnVal = minVal[node];
        mnPos = minPos[node];
        mxVal = maxVal[node];
        mxPos = maxPos[node];
        return;
    }
    int mid = (l + r) / 2;
    int lmnVal, lmnPos, lmxVal, lmxPos;
    int rmnVal, rmnPos, rmxVal, rmxPos;

    query(2 * node, l, mid, ql, qr, lmnVal, lmnPos, lmxVal, lmxPos);
    query(2 * node + 1, mid + 1, r, ql, qr, rmnVal, rmnPos, rmxVal, rmxPos);

    if (lmnVal < rmnVal)
    {
        mnVal = lmnVal;
        mnPos = lmnPos;
    }
    else
    {
        mnVal = rmnVal;
        mnPos = rmnPos;
    }

    if (lmxVal > rmxVal)
    {
        mxVal = lmxVal;
        mxPos = lmxPos;
    }
    else
    {
        mxVal = rmxVal;
        mxPos = rmxPos;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    minVal.resize(4 * n + 5);
    minPos.resize(4 * n + 5);
    maxVal.resize(4 * n + 5);
    maxPos.resize(4 * n + 5);

    build(1, 1, n);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        int mnVal, mnPos, mxVal, mxPos;
        query(1, 1, n, l, r, mnVal, mnPos, mxVal, mxPos);

        int val1 = p[mnPos];
        int val2 = p[mxPos];

        update(1, 1, n, mnPos, val2);
        update(1, 1, n, mxPos, val1);

        p[mnPos] = val2;
        p[mxPos] = val1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << " ";
        cout << p[i];
    }
    cout << endl;

    return 0;
}