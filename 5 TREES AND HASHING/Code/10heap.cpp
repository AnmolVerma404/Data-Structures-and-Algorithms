/*
A heap is a complete binary tree.
Priority queue comes in heap as either in min or max heao the root is smallest or largest and if we remove it we get the minimum or the maximum element in the list
Max heap -
        All child node are smaller than parent node
                50
              |    \
             30     20
           |   \   |  \
          15   10 8   16
          Use-
                STL priority queue of larger number higher priority
Min heap -
        All child node are smaller than parent node
                10
              |    \
             30     20
           |   \   |  \
          35   40 32   25
          Use-
                STL priority queue of smaller number higher priority
*/
// The C++ implementation of min && max heap using STL
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Max heap
    priority_queue<int> max_heap_pq;
    max_heap_pq.push(5);
    max_heap_pq.push(10);
    max_heap_pq.push(3);
    max_heap_pq.push(27);
    max_heap_pq.push(44);
    cout << "Max heap priority queue\n";
    while (!max_heap_pq.empty())
    {
        cout << max_heap_pq.top() << " ";
        max_heap_pq.pop();
    }
    priority_queue<int, vector<int>, greater<int>> min_heap_pq;
    min_heap_pq.push(5);
    min_heap_pq.push(10);
    min_heap_pq.push(3);
    min_heap_pq.push(27);
    min_heap_pq.push(44);
    cout << "\nMin heap priority queue\n";
    while (!min_heap_pq.empty())
    {
        cout << min_heap_pq.top() << " ";
        min_heap_pq.pop();
    }
    return 0;
}