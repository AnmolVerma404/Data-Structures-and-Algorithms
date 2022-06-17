// TC - O(log(min(a,b))) SC - O(1) 
import java.math.BigInteger;

public class eucledianAlgoForGCD {
    public static void main(String[] args) {
        int n1 = 24, n2 = 27;
        GCD(n1, n2);
        //OR
        BigInteger a = new BigInteger(Integer.toString(n1));
        BigInteger b = new BigInteger(Integer.toString(n2));
        BigInteger result = a.gcd(b);
        System.out.println(result);
    }

    public static void GCD(int n1, int n2) {
        int a = Integer.max(n1, n2);
        int b = Integer.min(n1, n2);
        int rem = 0;
        while (a % b != 0) {
            rem = a % b;
            a = b;
            b = rem;
        }
        System.out.println(rem);
    }
}
