public class blockSwapAlgo {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7,8};
        int idx = 4;
        lR(arr, idx, arr.length);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void bruteForce(int[] arr, int idx) {
        int i = 0, j = arr.length - 1;
        while (i < idx) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        for (int k = 0; k < arr.length; k++) {
            System.out.println(arr[k]);
        }
    }

    public static void lR(int[] arr, int d, int n) {
        blockSwap(arr, 0, d, n);
    }

    public static void blockSwap(int[] arr, int i, int d, int n) {
        if (d == 0 || d == n)
            return;
        if (d == n - d) {
            swap(arr, i, n - d + i, d);
            return;
        }
        if (d < n - d) {
            swap(arr, i, n - d + i, d);
            blockSwap(arr, i, d, n - d);
        } else {
            swap(arr, i, d, n - d);
            blockSwap(arr, n - d + i, 2 * d - n, d);
        }
    }

    public static void swap(int[] arr, int i, int j, int d) {
        for (int k = 0; k < d; k++) {
            int temp = arr[k + i];
            arr[k + i] = arr[k + j];
            arr[k + j] = temp;
        }
    }
}

/*
x = x ^ y
y = x ^ y
x = x ^ y
*/
/*
import java.util.*;

class GFG
{
	public static void leftRotate(int arr[], int d,
												int n)
	{
		leftRotateRec(arr, 0, d, n);
	}

	public static void leftRotateRec(int arr[], int i,
								int d, int n)
	{
		if(d == 0 || d == n)
			return;
		if(n - d == d)
		{
			swap(arr, i, n - d + i, d);
			return;
		}
		if(d < n - d)
		{
			swap(arr, i, n - d + i, d);
			leftRotateRec(arr, i, d, n - d);	
		}
		else 
		{
			swap(arr, i, d, n - d);
			leftRotateRec(arr, n - d + i, 2 * d - n, d);
		}
	}

public static void printArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		System.out.print(arr[i] + " ");
	System.out.println();
}

public static void swap(int arr[], int fi,
						int si, int d)
{
	int i, temp;
	for(i = 0; i < d; i++)
	{
		temp = arr[fi + i];
		arr[fi + i] = arr[si + i];
		arr[si + i] = temp;
	}
}

public static void main (String[] args)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	leftRotate(arr, 4, 7);
	printArray(arr, 7);	
}
}

*/