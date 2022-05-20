public class maxBitLen {
    public static void main(String[] args) {
        String s = "1110000011011";
        oneBit(s);
    }

    public static void oneBit(String s) {
        int n = s.length();
        // int mxSubArray = 0, mxSoFar = Integer.MAX_VALUE;
        // int start = -1, end = -1;
        // for(int i = 0;i<n;i++){
        //     if(s.charAt(i)=='0'){
        //         if(start!=-1){
        //             mxSubArray = Math.max(mxSubArray, end - start + 1);
        //             start = -1;
        //             end = -1;
        //         }
        //     }else if(s.charAt(i)=='1'){
        //         if(start == -1){
        //             start = i;
        //         }
        //     }
        // }
        // System.out.println(mxSubArray);
        //OR
        boolean check = true;
        int i = 0,j = 0;
        int mx = 0;
        while(i<n){
            if(s.charAt(i)=='1'){
                i++;
            }else if(s.charAt(i)=='0' && check == true){
                check = false;
            }else if(s.charAt(i)=='0' && check != true){
                while(j<i && s.charAt(j)!=0) j++;
                j++;
            }
            mx = Math.max(mx, i-j+1);
            i++;
        }
        System.out.println(mx);
    }
}
