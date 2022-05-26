// TC - O(n^1.59) SC - O(n)
public class karatsubaAlgo {
    public static void main(String[] args) {
        long x = 2, y = 1000;
        // System.out.println(145);
        long a = karatsuba(x, y);
        System.out.println(a);
    }

    public static long karatsuba(long x, long y) {
        long aLen = size(x), bLen = size(y);
        long a = 0, b = 0, c = 0, d = 0;
        long n = Math.max(aLen, bLen);
        n = n / 2 + n % 2;
        long mid = (long) Math.pow(10, n);
        // System.out.println(mid);
        if(n<10){
            return x*y;
        }
        a = x / mid;
        b = x - (a * mid);
        c = y / mid;
        d = y - (c * mid);
        // System.out.println(a);
        // System.out.println(b);
        // System.out.println(c);
        // System.out.println(d);
        long ac = karatsuba(a, b);
        long bd = karatsuba(b, d);
        long adcb = karatsuba(a+b, c+d);
        return ac*((long)Math.pow(10, n)) + adcb*((long)Math.pow(10, n/2)) + bd;
    }

    public static long size(long a) {
        int s = 0;
        while (a > 0) {
            s++;
            a /= 10;
        }
        return s;
    }
}