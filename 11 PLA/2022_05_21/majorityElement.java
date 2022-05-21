import java.util.HashMap;

public class majorityElement {
    public static void main(String[] args) {
        int[] arr = { 1,1,1,2,2,2,2,2};
        int n = arr.length;
        mE(arr,n);
    }
    // public static void bruteForce(int[] arr,int n){
        
    // }
    public static void mE(int[] arr,int n){
        HashMap<Integer,Integer> mp = new HashMap<>();
        int mx = Integer.MIN_VALUE;
        for(var i : arr){
            if(!mp.containsKey(i)){
                mp.put(i,1);
            }else{
                mp.put(i, mp.get(i)+1);
            }
            mx = Math.max(mx, mp.get(i));
            if(mx>=n/2){
                System.out.println(i);
                break;
            }
        }
    }
}
