// https://www.geeksforgeeks.org/strobogrammatic-number/
// TC - O(n) SC - O(n) 
import java.util.*;

public class strobogrammaticNumber {
    public static void main(String[] args) {
        //Also do it with stack and map
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        // int n = 19861;
        // bruteForce(n);
        stackImp(n);
        // mapImp(n);
    }

    public static void bruteForce(int n) {
        int num = 0, temp = n;
        boolean crom = true;
        while (n > 0) {//n = 19861
            int t = n % 10;
            n/=10;
            if (t == 0 || t == 1 || t == 8) {
                num = num*10 + t;
            } else if (t == 6) {
                num = num*10 + 9;
            } else if (t == 9) {
                num = num*10 + 6;
            } else {
                crom = false;
                break;
            }
        }
        if (crom == false || temp != num) {
            System.out.println("Not a strobogrammatic Number");
        } else if (temp == num) {
            System.out.println("It's a strobogrammatic Number");
        }
    }

    public static void stackImp(int n) {
        List<Integer>l = new LinkedList();
        while(n>0){
            l.add(n%10);
            n/=10;
        }
        int size = l.size();
        Stack<Integer> st1 = new Stack<>();
        Stack<Integer> st2 = new Stack<>();
        int i = 0, j = size-1;
        int leftOut = -1;
        if(size%2!=0){
            leftOut = l.get(size/2);
        }
        while(i<j){
            st1.add(l.get(i++));
            st2.add(l.get(j--));
        }
        boolean crom = true;
        while(st1.size()!=0){
            int top1 = st1.pop();
            int top2 = st2.pop();
            if(top1 == 6 && top2 == 9) continue;
            else if(top1 == 9 && top2 == 6) continue;
            else if(top1 == 0 && top2 == 0) continue;
            else if(top1 == 1 && top2 == 1) continue;
            else if(top1 == 8 && top2 == 8) continue;
            else crom = false;
        }
        if(leftOut!=-1 && !(leftOut == 0 || leftOut == 1 || leftOut == 8)) crom = false;
        if(crom == false) System.out.println("Not a PseudoCromatic Number");
        else System.out.println("It's a PseudoCromatic Number");
    }

    public static void mapImp(int n) {
        
    }
}