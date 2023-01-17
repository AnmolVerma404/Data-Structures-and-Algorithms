/*
 * A Segment Tree is a data structure that is used to efficiently store and retrieve information about ranges of values in an array.
 * If a range is given there are three ways to find the minimum in the range if we have a segment tree constructed.
 * * * * * 1) Partial Overlap
 * * * * * * * * * We must look in both left and right and try to find total or no overlap
 * * * * * 2) Total Overlap
 * * * * * * * * * Just return the number bound to this range which have a total overlap
 * * * * * 3) No Overlap
 * * * * * * * * * Return a MAX_INT number.
 * To find the number of node/elements of the binary tree we need to form with size of the array
 * * * * * 1) If the array.size() is a power of 2. Then nodes = array.size()*2-1 Eg:- If size = 4 -> nodes = 4*2-1 = 7
 * * * * * 2) If the size of array is not of power of 2. Then find the next power of 2 from the number.
 * * * * * And apply the same formula Eg:- array.size() == 5 -> 4<5<8. nodes = 8*2-1 = 15
 * In a question their will be given an array. You will build a segment tree out of it. And again store it in an array
 * To get the left, right, and the parent element we have formula i.e. 2i+1,2i+2, (i-1)/2 respectively.
 */