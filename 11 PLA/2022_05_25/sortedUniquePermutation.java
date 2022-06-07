// Time Complexity: O(n*m)
public class sortedUniquePermutation {
    public static void main(String[] args) {
        String str = "";
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        printComb(arr, 4);
    }

    /*
    public static void perm(int[] arr,String s){
        if(s.length() >= 2){
            System.out.println(s);
            return;
        }
        for(var i : arr){
            s+=i;
            System.out.println(s);
            perm(arr,s);
            s = "";
        }
        return;
    }
    */
    public static void printComb(int[] arr, int r) {
        int[] data = new int[r];
        combUtil(arr, data, 0, arr.length - 1, 0, r);
    }

    public static void combUtil(int[] arr, int[] data, int start, int end, int idx, int r) {
        if (idx == r) {
            for (int i = 0; i < r; i++) {
                System.out.print(data[i]);
            }
            System.out.println("");
            return;
        }
        for (int i = start; i <= end && end - i + 1 >= r - idx; i++) {
            data[idx] = arr[i];
            combUtil(arr, data, i + 1, end, idx + 1, r);
        }
    }
}