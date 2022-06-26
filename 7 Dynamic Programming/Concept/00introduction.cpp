/*
Dynamic Programming(DP)
Those who cannot remember the past are condemned to repeat it.
DP problems are solved mostly in 
    Memorization(aka Memoization)  - Top Down
    Tabulation    - Bottom Up(Trick to remember - is the word tabulation 'b' character come which is very unique b/w both the word and Bottom Up starts with 'b' character!!!)

In term of Time/Space complexity
Recursion < Memoization < Tabulation < Tabulation + Space Optimization 

Memorization - It's a way of solving DP problem in which we build up the solution from top to down, therefore it's known as Top-Down Approach
In Top Down we start from nth call and go to the base case then start building our solution from there, also we store the calculated result in a dp vector/list/array which helps us to reuse and not to recalculate the already calculated result.
In this we break a massive problem into smaller subproblems.
Here stack space is required, i.e. when recursion call is called it will first sol

Tabulation - It's a way of solving DP problem in which we build up the solution from bottom to Up, it's also known as Bottom-Up Approach, the base case in memoization are most time the starting case for tabulation approach
In Bottom-Up Approach we solve the fundamental low level problem and integrate them into a larger one.

Q) How to figure out that the problem need to be solved using DP?
The question which generally says, count the number of steps or find the maximum or the minimum output when there are multiple ways to solve
When the problem states count the number of ways/steps then first step is to think about recursion as it will tell you all the ways available.

Shortcut for solving any recursion/DP problem
1) Try to represent the problem in terms of index
2) Do all possible stuff on that index according to the problem statement 
3) If the problem says count all the ways then sum up all the stuff
                       find minimum then take minimim of all stuff
                       find maximum then take maximum of all stuff
Also remember the base case is really-really important as is the memoization way, most of the solution will be starting from their only.

After this you will be able to write the recursion then memoize it, then convert it into tabulation then space optimise it. 
*/