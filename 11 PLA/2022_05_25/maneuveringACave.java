public class maneuveringACave {
    public static void main(String[] args) {
        int n = 5, m = 4;
        int[][] dp = new int[n + 1][m + 1];
        System.out.println(numberOfPath(n, m));
        System.out.println(numberOfPathDP(dp, n, m));
    }

    public static int numberOfPathDP(int[][] dp, int n, int m) {
        if (m == 1 || n == 1) {
            return dp[n][m] = 1;
        }
        if (dp[n][m] == 0) {
            dp[n][m] = numberOfPathDP(dp, n - 1, m) + numberOfPathDP(dp, n, m - 1);
        }
        return dp[n][m];
    }

    public static int numberOfPath(int n, int m) {
        // Time Complexity - O(2^n)
        if (m == 1 || n == 1) {
            return 1;
        }
        return numberOfPath(n - 1, m) + numberOfPath(n, m - 1);
    }
}