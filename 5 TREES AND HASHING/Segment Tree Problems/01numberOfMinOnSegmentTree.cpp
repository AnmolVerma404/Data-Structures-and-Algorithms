#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2, MOD = 1e9 + 7;
/*
 * pair<int,int> in pair first and second will be storing
 * first  -> minimum element in the range of st and en
 * second -> occurrence of that minimum
 */
pair<int, int> tree[4 * N];
int a[N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node].first = a[st];
        tree[node].second = 1;
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    /*
     * If left < right  -> store left in the node as it's the minimum and same with freq
     * If right < left  -> store right in the node as it's the minimum and same with freq
     * If left == right -> store any of then in the tree.first but in tree.second store the sum of both
     * As left and right min element be Eg:- 2. Therefore,
     * tree[node].first = 2;
     * tree[node].second = tree[2*node].second(1 or more) + tree[2*node+1].second(1 or more)
     */
    if (tree[2 * node].first < tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else if (tree[2 * node + 1].first < tree[2 * node].first)
    {
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }
}

pair<int, int> query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return {MOD, -1};
    }
    if (st >= l && en <= r)
    {
        return tree[node];
    }
    int mid = (st + en) / 2;
    pair<int, int> left = query(2 * node, st, mid, l, r);
    pair<int, int> right = query(2 * node + 1, mid + 1, en, l, r);
    pair<int, int> res;
    if (left.first < right.first)
    {
        return left;
    }
    else if (right.first < left.first)
    {
        return right;
    }
    else
    {
        return {left.first, left.second + right.second};
    }
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        tree[node].first = val;
        tree[node].second = 1;
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

    if (tree[2 * node].first < tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else if (tree[2 * node + 1].first < tree[2 * node].first)
    {
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            pair<int, int> ans = query(1, 0, n - 1, l, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }

    return 0;
}