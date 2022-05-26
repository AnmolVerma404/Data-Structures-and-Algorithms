// TC - O(n) SC - O(1)
public class lexicographicalFirstPalindromicString {
    static char MAX_CHAR = 26;
    public static void main(String[] args) {
        String s = "malayalam";
        System.out.println(LFPS(s));
    }

    public static String LFPS(String s) {
        int n = s.length();
        int[] freq = new int[MAX_CHAR];
        findFreq(s, freq);
        if (!canBeLFPS(s, freq)) {
            System.out.println("String can be lexicographical first palindromic string");
        }
        String oddStr = findOddAndRemoveIt(freq);
        String front = "", rear = "";
        for (int i = 0; i < MAX_CHAR; i++) {
            String temp = "";
            if (freq[i] != 0) {
                char ch = (char) (i + 'a');
                for (int j = 0; j < freq[i] / 2; j++) {
                    temp += ch;
                }
                front += temp;
                rear = temp + rear;
            }
        }
        return (front + oddStr + rear);
    }

    public static boolean canBeLFPS(String s, int[] freq) {
        int count = 0;
        int n = freq.length;
        for (int i = 0; i < n; i++) {
            if (freq[i] % 2 != 0) {
                count++;
            }
        }
        if (s.length() % 2 == 0) {
            if (count % 2 != 0)
                return false;
            else
                return true;
        }
        if (count != 1)
            return false;
        return true;
    }

    public static void findFreq(String s, int[] freq) {
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
        }
    }

    public static String findOddAndRemoveIt(int[] freq) {
        String oddStr = "";
        for (int i = 0; i < MAX_CHAR; i++) {
            if (freq[i] % 2 != 0) {
                freq[i]--;
                oddStr += (char) (i + 'a');
                return oddStr;
            }
        }
        return oddStr;
    }
}