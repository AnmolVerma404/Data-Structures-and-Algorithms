/*
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 2;
int tree[4 * N], a[N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return INT_MIN;
    }
    if (st >= l && en <= r)
    {
        return tree[node];
    }
    int mid = (st + en) / 2;
    int left = query(2 * node, st, mid, l, r);
    int right = query(2 * node + 1, mid + 1, en, l, r);
    return max(left, right);
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val; // Not needed if we are not building the tree again
        tree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, idx, val);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);

    while (1)
    {
        int type;
        cin >> type;
        if (type == -1)
        {
            break;
        }
        else if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans << "\n";
        }
        else if (type == 2)
        {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
            cout << query(1, 0, n - 1, 0, n - 1) << "\n";
        }
    }

    return 0;
}