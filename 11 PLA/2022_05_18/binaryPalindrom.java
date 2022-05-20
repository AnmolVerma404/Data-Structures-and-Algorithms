public class binaryPalindrom {
    public static void main(String[] args) {
        int n = 17;
        bP(n);
    }

    public static void bP(int n) {
        String bNum = intToBinary(n);
        StringBuilder sb = new StringBuilder();
        String temp = bNum;
        sb.append(bNum);
        sb.reverse();
        String rev = sb.toString();
        //  OR
        // int s = bNum.length();
        // boolean isP = true;
        // for(int i = 0;i<bNum.length()/2;i++){
        //     if(bNum.charAt(i)!=bNum.charAt(s-i+1)){
        //         isP = false;
        //     }
        // }
        int size1 = temp.length();
        int size2 = rev.length();
        if (temp == rev) {
            System.out.println("It's a Binary Palindrom");
        } else {
            System.out.println(temp);
            System.out.println(rev);
            System.out.println("It's not a Binary Palindrom");
        }
    }

    public static String intToBinary(int n) {
        String res = "";
        while (n != 0) {
            int rem = n % 2;
            n /= 2;
            res += rem;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(res);
        sb.reverse();
        return sb.toString();
    }
}