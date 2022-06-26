/*
Dynamic Programming(DP)
Those who cannot remember the past are condemned to repeat it.
DP problems are solved mostly in 
    Memorization(aka Memoization)  - Top Down
    Tabulation    - Bottom Up(Trick to remember - is the word tabulation 'b' character come which is very unique b/w both the word and Bottom Up starts with 'b' character!!!)

Memorization - It's a way of solving DP problem in which we build up the solution from top to down, therefore it's known as Top-Down Approach
In Top Down we start from nth call and go to the base case then start building our solution from there, also we store the calculated result in a dp vector/list/array which helps us to reuse and not to recalculate the already calculated result.
In this we break a massive problem into smaller subproblems.
Here stack space is required, i.e. when recursion call is called it will first sol

Tabulation - It's a way of solving DP problem in which we build up the solution from bottom to Up, it's also known as Bottom-Up Approach, the base case in memoization are most time the starting case for tabulation approach
In Bottom-Up Approach we solve the fundamental low level problem and integrate them into a larger one.
*/