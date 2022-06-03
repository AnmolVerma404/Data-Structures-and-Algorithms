import java.util.Stack;

public class theCelebrityProblem {
    static boolean knows(int a, int b, int[][] m) {
        return m[a][b] == 1 ? true : false;
    }

    static int findCeleb(int[][] m) {
        int n = m.length;
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; ++i) {
            st.push(i);
        }
        while (st.size() > 1) {
            int a = st.pop();
            int b = st.pop();
            if (knows(a, b, m)) {
                st.push(b);
            } else {
                st.push(a);
            }
        }
        if (st.empty()) {
            return -1;
        }
        int c = st.pop();
        for (int i = 0; i < n; i++) {
            if (i != c && (knows(c, i, m) || !knows(i, c, m))) {
                return -1;
            }
        }
        return c;
    }

    public static void main(String[] args) {
        int m[][] = { { 1, 1, 1, 1 },
                { 0, 0, 1, 0 },
                { 0, 0, 1, 0 },
                { 1, 1, 1, 1 } };
        int res = findCeleb(m);
        if (res == -1) {
            System.out.println("No Celebrity Found");
        } else {
            System.out.println("Celebrity found at " + res);
        }
    }
}
