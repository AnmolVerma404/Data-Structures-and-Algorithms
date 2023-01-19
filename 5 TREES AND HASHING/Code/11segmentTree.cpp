/*
 * A Segment Tree is a data structure that is used to efficiently store and retrieve information about ranges of values in an array.
 * If a range is given there are three ways to find the minimum in the range if we have a segment tree constructed.
 *         1) Partial Overlap
 *                 We must look in both left and right and try to find total or no overlap
 *         2) Total Overlap
 *                 Just return the number bound to this range which have a total overlap
 *         3) No Overlap
 *                 Return a INT_MAX number. Or return 0. Depends on code. I have returned 0.
 *                 INT_MAX or INT_MIN is returned in case when we need to find the min or
 *                 the max element in a range l to r respectively.
 * This is the code for finding the sum in the range l and r. For max num in range l and r. Look 12th file
 * To find the number of node/elements of the binary tree we need to form with size of the array
 *         1) If the array.size() is a power of 2. Then nodes = array.size()*2-1 Eg:- If size = 4 -> nodes = 4*2-1 = 7
 *         2) If the size of array is not of power of 2. Then find the next power of 2 from the number.
 *         And apply the same formula Eg:- array.size() == 5 -> 4<5<8. nodes = 8*2-1 = 15
 * In a question their will be given an array. You will build a segment tree out of it. And again store it in an array
 * To get the left, right, and the parent element we have formula i.e. 2i+1,2i+2, and (i-1)/2 respectively. This is when they are stored in 0 based indexing.
 * If we are starting from 1 then we can use 2i,2i+1, and (i-2)/2
 *
 * TC analysis
 * There were two ways of solving this problem without segment tree, but the TC is larger.
 *         1) Find the sum from left to right O(N) and update index in O(1)
 *         2) Use prefix sum to store sum and use i-1>=0?v[right]-v[left-1]:v[right] to find
 *            the sum in O(1) but for updating the index O(N) to update the prefix array
 *         3) Use Segment Tree and get O(log(n)) for both sum and update.
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
int a[N], tree[4 * N];

/*
 * node - it stores index of tree.
 * st   - start of the current segment
 * en   - end of the current segment
 */
void build(int node, int st, int en)
{
    if (st == en)
    {
        /*
         * At the base case the sum within range.size() == 1 will be the element itselt
         * This will create a tree and then parent can be the sum of the left and right child
         */
        tree[node] = a[st];
        return;
    }
    /*
     * mid      -> To find the mid of the segment and further divide the range. So at some time base case is true
     * 2*node   -> Formula for the left child of the node index
     * 2*node+1 -> Formula for the right child of the node index
     */
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    /*
     * Finally calculate the curr node segment sum
     * For example given an array [1,2,3,4,........,n-1,n]
     * At some case if it break down to range [1,2]
     *               [1,2]
     *              /    |
     *            [1]   [2]
     * In both 1 and 2 st == en therefore we will set that node to 1 and 2.
     * This will return and tree[node] = (tree[2*node]==1) + (tree[2*node + 1]==2) ==> 3
     * Where 3 is the sum of in the range of [1,2].
     */
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

/*
 * node -> it stores index of tree.
 * st   -> start of the current segment
 * en   -> end of the current segment
 * l    -> this will store the left most index of the range query
 * r    -> this will store the right most index of the range query
 */
int query(int node, int st, int en, int l, int r)
{
    /*
     * No Overlap condition
     * When the start is greater than the right most index.
     * And the left is end is less then the left most index.
     * Sequence -> en .... l || r .... st
     */
    if (st > r || en < l)
    {
        return 0;
    }

    /*
     * Total Overlap condition
     * The current segment lies inside the l and r range
     * Therefore no need of further recurcive call.
     * As the result of tree[node] will be added to the query of l and r sum.
     *  Sequence -> l .... st .... en .... r
     */
    if (st >= l && en <= r)
    {
        return tree[node];
    }

    /*
     * Partial Overlap condition
     * For example given an array [1,2,3,4,........,n-1,n]
     * At some case if it break down to range [1,2]
     *               [1,2]
     *              /    |
     *            [1]   [2]
     * If l = 1. Therefore tree[node]==1 will return 0. As base case
     * And 2 is partial overlap in [1,2] therefore right will return 2. As it's total overlap.
     * Sequence -> st .... l .... en .... r || l .... st .... r .... en
     */
    int mid = (st + en) / 2;
    int left = query(node * 2, st, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, en, l, r);
    return left + right;
}

int main()
{
    int n;
    cin >> n;

    /*
     * Here we are taking input from 0-n
     * But when calling build we are passing 1, and same in printing out the result
     * This is because 1 is the root of the BT, it't not of the array 'a'
     * Array 'a' will have st and en. And the node variable is associated with Array 'tree'
     */
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    /*
     * Print the segment tree formed.
     */
    for (int i = 1; i < n * 2 - 1; ++i)
    {
        cout << tree[i] << "\n";
    }
    /*
     * Range Sum Query
     */
    while (true)
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
    }
    return 0;
}