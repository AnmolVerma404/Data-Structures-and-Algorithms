public class divideSwapMergeBN {
    public static void main(String[] args) {
        String bNum = "12345";
        int n = bNum.length();
        String first="",second="";
        System.out.println(n);
        int i = 0;
        for(i = 0;i<n/2;i++){
            first+=bNum.charAt(i);
        }
        for(;i<n;i++){
            second+=bNum.charAt(i);
        }
        // System.out.println(first + " " + second);
        String splitedSwapedBN = second + first;
        System.out.println(bNum);
        System.out.println(splitedSwapedBN);
    }
    public static String merge(String s1, String s2){
        String s3 = s1+s2;
        return "";
    }
}
