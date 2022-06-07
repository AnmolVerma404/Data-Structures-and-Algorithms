// https://www.geeksforgeeks.org/print-distinct-sorted-permutations-with-duplicates-allowed/
// Java program to print all permutations of a string
// in sorted order.
// Time Complexity - O(N*M)
import java.io.*;
import java.util.*;

class allPermutation {

// Calculating factorial of a number
static int factorial(int n) {
	int f = 1;
	for (int i = 1; i <= n; i++)
	f = f * i;
	return f;
}

// Method to print the array
static void print(char[] temp) {
	for (int i = 0; i < temp.length; i++)
	System.out.print(temp[i]);
	System.out.println();
}

// Method to find total number of permutations
static int calculateTotal(char[] temp, int n) {
	int f = factorial(n);

	// Building HashMap to store frequencies of
	// all characters.
	HashMap<Character, Integer> hm =
					new HashMap<Character, Integer>();
	for (int i = 0; i < temp.length; i++) {
	if (hm.containsKey(temp[i]))
		hm.put(temp[i], hm.get(temp[i]) + 1);
	else
		hm.put(temp[i], 1);
	}

	// Traversing hashmap and finding duplicate elements.
	for (Map.Entry e : hm.entrySet()) {
	Integer x = (Integer)e.getValue();
	if (x > 1) {
		int temp5 = factorial(x);
		f = f / temp5;
	}
	}
	return f;
}

static void nextPermutation(char[] temp) {

	// Start traversing from the end and
	// find position 'i-1' of the first character
	// which is greater than its successor.
	int i;
	for (i = temp.length - 1; i > 0; i--)
	if (temp[i] > temp[i - 1])
		break;

	// Finding smallest character after 'i-1' and
	// greater than temp[i-1]
	int min = i;
	int j, x = temp[i - 1];
	for (j = i + 1; j < temp.length; j++)
	if ((temp[j] < temp[min]) && (temp[j] > x))
		min = j;

	// Swapping the above found characters.
	char temp_to_swap;
	temp_to_swap = temp[i - 1];
	temp[i - 1] = temp[min];
	temp[min] = temp_to_swap;

	// Sort all digits from position next to 'i-1'
	// to end of the string.
	Arrays.sort(temp, i, temp.length);

	// Print the String
	print(temp);
}

static void printAllPermutations(String s) {

	// Sorting String
	char temp[] = s.toCharArray();
	Arrays.sort(temp);

	// Print first permutation
	print(temp);

	// Finding the total permutations
	int total = calculateTotal(temp, temp.length);
	for (int i = 1; i < total; i++)
	nextPermutation(temp);
}

// Driver Code
public static void main(String[] args) {
	String s = "AAB";
	printAllPermutations(s);
}
}
