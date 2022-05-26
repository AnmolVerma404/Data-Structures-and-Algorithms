// https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
// TC - nlogn SC - O(1)
public class reminderTheorem {
    public static void main(String[] args) {
        //Chienese reminder theorem
        /*
        NUM     3   4   5       
        REM     2   3   1
              x/3 = 2 can also be written in general form i.e. x = 2(mod 3)
              x/4 = 3
              x/5 = 1
            Find x?(i.e.11)
            Here:- a = {2,3,1}
                   m = {3,4,5}
        */
        /*
        MOD~%
        - x === a1(Mod(m1))
          where m1 is the divisor, a is the reminder
        - x === (a1M1(M1`) + a2M2(M2`) + .... + anMn(Mn`))MOD(M)
        where Mn` is the reciprocal of Mn
        To calculate M we have
        M = m1*m2*m3*.....*mn
        To calculate M1,M2,M3,....,Mn we have
        M1 = M/m1
        M2 = M/m2
        M3 = M/m3
        || || ||
        || || ||
        || || ||
        Mn = M/mn
        */
        
    }
    public int chieneseTheorem(int [] arr1, int [] arr2, int k){
        // int x = 1;
        // while(true){
        // }
        return 0;
    }
}
