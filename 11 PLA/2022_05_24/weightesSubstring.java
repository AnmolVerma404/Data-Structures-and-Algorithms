public class weightesSubstring {
    public static void main(String[] args) {
        String s = "HelloWorld";
        String wt = "4987653215";
        int k = 20;
        wtSubstring(s, wt, k);
    }

    public static void wtSubstring(String s, String wt, int k) {
        int n = s.length();
        int m = wt.length();
        for (int i = 0; i < n; i++) {
            String ss = "";
            int sum = 0;
            for (int j = i; j < n; j++) {
                ss += s.charAt(j);
                int w = wt.charAt(j) - '0';
                sum += w;
                if (sum <= k) {
                    System.out.println(ss);
                }
            }
        }
    }
}
