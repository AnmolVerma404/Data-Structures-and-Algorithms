/*
How to know if a question can be solved by stack?
If you solve it in brute force way and the solution may be comming in O(n)
Eg - CASE I
     for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){//-> the second for loop is independent on the first one
        }
    }
    CASE II
    for(int i =0;i<n;i++){
        for(int j =0;j<i;j++){//-> the second for loop is dependent on the first one with different combination
        }
    }
    In CASE II you can 100% say that we can use stack to solve it!!!
*/