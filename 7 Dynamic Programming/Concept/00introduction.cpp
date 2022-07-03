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

**Important**
How to read my explanation
1 Read what's written in the top of code file. It will include the problem statement/or the explanation of it
2 Go to the main function and read line by line (i.e. if function call go to it and when it's finished go to main and to the next function it there is one)
3 Function's given are in the order of TC and SC therefore the second solution/function in the main function will be better than the first one.
4 While in the function if it's recursive then read the base case after reading the resursive code, it will explain you what is the need of that base condition.
Also the return condition should be readed after the base condition's and other condition are readen. 


Hope you like my work😀😀
*/