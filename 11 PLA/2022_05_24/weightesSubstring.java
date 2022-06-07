// Time Complexity: O(N^2)
public class weightesSubstring {
    public static void main(String[] args) {
        String s = "HelloWorld";
        // String wt = "4987653215";
        String wt = "1111111111";
        int k = 20;
        wtSubstring(s, wt, k);//
        // opWtSubstring(s, wt, k);//29
    }

    public static void wtSubstring(String s, String wt, int k) {
        int n = s.length();
        int m = wt.length();
        int tsbs = 0;
        for (int i = 0; i < n; i++) {
            String ss = "";
            int sum = 0;
            for (int j = i; j < n; j++) {
                ss += s.charAt(j);
                int w = wt.charAt(j) - '0';
                sum += w;
                if (sum <= k) {
                    tsbs++;
                    System.out.println(ss);
                }
            }
        }
        System.out.println(tsbs);
    }
    public static void opWtSubstring(String s, String wt, int k){
        int n = s.length();
        int m = wt.length();
        int tw = 0;
        for(int i = 0;i<n;i++){
            tw+= (wt.charAt(i)-'0');
        }
        for(int i = m-1;i>=0;i--){
            
        }
        // System.out.println(tw);
    }
}
