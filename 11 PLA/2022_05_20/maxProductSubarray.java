import javax.swing.plaf.synth.SynthSpinnerUI;

public class maxProductSubarray {
    public static void main(String[] args) {
        int[] arr = { -1,-2,0,3,-5,2};
        int n = arr.length;
        subArray(arr, n);
    }

    public static void subArray(int[] arr, int n) {
        int mx = 0;
        int curr = 1;
        boolean notZero = false; 
        for (int i = 0; i < n; i++) {
            if(arr[i]!=0){
                notZero = true;
            }
            if (arr[i] == 0) {
                curr = 1;
            } else {
                curr *= arr[i];
            }
            mx = Math.max(mx, curr);
        }
        if(!notZero) System.out.println(0);
        else System.out.println(mx);
    }
}
