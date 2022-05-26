// TC - O(n)  SC - O(1) 
public class divideSwapMergeBN {
    public static void main(String[] args) {
        String bNum = "10011011";
        int n = bNum.length();
        // nibbles(bNum, n);
        System.out.println(nibbleBitwise(n));
        // System.out.println((0x0F));
    }

    public static void nibbles(String bNum, int n) {
        String first = "", second = "";
        System.out.println(n);
        int i = 0;
        for (i = 0; i < n / 2; i++) {
            first += bNum.charAt(i);
        }
        for (; i < n; i++) {
            second += bNum.charAt(i);
        }
        // System.out.println(first + " " + second);
        String splitedSwapedBN = second + first;
        System.out.println(bNum);
        System.out.println(splitedSwapedBN);
    }

    public static int nibbleBitwise(int n) {
        return ((n & 0x0F) << 4 | (n & 0xF0) >> 4);
    }
}
