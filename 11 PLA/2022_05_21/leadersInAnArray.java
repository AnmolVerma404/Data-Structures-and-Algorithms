// TC - O(n) SC - O(n)
public class leadersInAnArray {
    public static void main(String[] args) {
        // int[] arr = { 10, 8, 7, 9, 11, -2, 0, 8, 9, 10 };
        int[] arr = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        int n = arr.length;
        findLeaders(arr, n);
        // for (int i = 0; i < 1 / arr.length; i++) {
        //     System.out.println(arr[i]);
        // }
    }

    public static void findLeaders(int[] arr, int n) {
        int mx = arr[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            mx = Math.max(mx, arr[i]);
            if (arr[i] >= mx) {
                System.out.println(mx);
            }
        }
    }
}
