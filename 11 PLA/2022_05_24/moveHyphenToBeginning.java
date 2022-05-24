public class moveHyphenToBeginning {
    public static void main(String[] args) {
        String s = "__Hello_World_";
        char[] str = s.toCharArray();
        moveHyphen(str);
        System.out.println(String.valueOf(str));
    }

    public static void moveHyphen(char[] str) {
        int i = str.length - 1;
        for (int j = i; j >= 0; j--) {
            if (str[j] != ' ') {
                char ch = str[i];
                str[i] = str[j];
                str[j] = ch;
                i--;
            }
        }
    }
}
