import javax.swing.plaf.synth.SynthSpinnerUI;

public class maxProductSubarray {
    public static void main(String[] args) {
        int[] arr = { -1, -2, 0, 3, -5, 2 };
        int n = arr.length;
        // subArray(arr, n);
        maxSubarrayProduct(arr, n);
    }

    public static void maxSubarrayProduct(int arr[], int n) {
        int mx = arr[0];
        int mn = arr[0];
        int res = arr[0];
        for (int i = 0; i < n; i++) {
            int temp = Math.max(arr[i], Math.max(arr[i] * mx, arr[i] * mn));
            mn = Math.min(arr[i], Math.min(arr[i] * mx, arr[i] * mn));
            mx = temp;
            res = Math.max(res, mx);
        }
        System.out.println(res);
    }

    public static void subArray(int[] arr, int n) {
        int mx = 0;
        int curr = 1;
        boolean notZero = false;
        int negativeCount = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                negativeCount++;
            }
            if (arr[i] != 0) {
                notZero = true;
            }
            if (arr[i] == 0) {
                curr = 1;
                negativeCount = 0;
            } else {
                curr *= arr[i];
            }
            mx = Math.max(mx, curr);
        }
        if (!notZero)
            System.out.println(0);
        else
            System.out.println(mx);
    }
}
