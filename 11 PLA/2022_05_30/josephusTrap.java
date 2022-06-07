import java.util.ArrayList;
/*
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
public class josephusTrap {
    public static void main(String[] args) {
        int n = 14;
        int s = 0;
        int k = 2;
        //M-1
        System.out.println(jose1(n, k));
        ArrayList<Integer> l = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            l.add(i);
        }
        // jose2(l, k, s);
    }

    public static int jose1(int n, int k) {
        if (n == 1)
            return 1;
        return ((jose1(n - 1, k) + k - 1) % n + 1);
    }

    public static void jose2(ArrayList<Integer> l, int k, int s) {

    }
}