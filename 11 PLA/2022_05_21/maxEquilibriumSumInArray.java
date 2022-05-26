// TC - O(n) SC - O(1)
public class maxEquilibriumSumInArray {
    public static void main(String[] args) {
        // int[] arr = { 3, 4, 10, 17 };
        // int[] arr = { -1,2,3,0,3,2,-1};
        int []arr = { -2, 5, 3, 1, 2, 6, -4, 2 };
        int n = arr.length;
        maxEquilibrium(arr, n);
    }

    public static void maxEquilibrium(int[] arr, int n) {
        int i = 0, j = n - 1;
        int ps = 0, ss = 0;
        int mx = Integer.MIN_VALUE;
        int count = 0;
        // while (i-1 <= j) {
        while (count < n) {
            if (ps > ss) {
                System.out.println("a");
                ss += arr[j];
                j--;
                count++;
            } else if (ps < ss) {
                System.out.println("b");
                ps += arr[i];
                i++;
                count++;
            } else if (ps == ss) {
                System.out.println("c");
                // System.out.println(i+ " " +j);
                mx = Math.max(mx, ps);
                ss += arr[j--];
                ps += arr[i++];
                count+=2;
                // System.out.println(ps + " " + ss);
            }
        }
        System.out.println(mx);
    }
}
