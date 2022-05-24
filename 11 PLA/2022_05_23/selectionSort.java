public class selectionSort {
    public static void main(String[] args) {
        int[] arr = { -81, -12, 0, 6, 44, 2, 10 };
        int n = arr.length;
        sSort(arr, n);
    }

    public static void sSort(int[] arr,int n){
        for(int i = 0;i<n;i++){
            int mn = arr[i];
            int minIdx = 0;
            for(int j = i+1;j<n;j++){
                if(mn<arr[j]){
                    mn = arr[j];
                    minIdx = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
        for(var i : arr){
            System.out.println(i);
        }
    }
}