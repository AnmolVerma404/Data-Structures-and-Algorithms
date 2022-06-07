import java.util.LinkedList;
/*
Two pointer
TC - O(N) ASC - O(1)
Hash Map
TC - O(N) ASC - O(N)
*/
public class loopDetection {
    public static class linkedList {
        int val;
        linkedList next;

        linkedList(int val) {
            this.val = val;
            next = null;
        }
    }

    public static void main(String[] args) {
        linkedList obj = new linkedList(1);
        linkedList head = obj;
        for(int i = 1;i<=5;i++){
            obj.next = new linkedList(i);
            obj = obj.next;
        }
        obj.next = head;
        linkedList slow = head, fast = head;
        boolean loopPresent = false;
        while (slow != null && fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (slow == fast) {
                loopPresent = true;
                break;
            }
        }
        if (loopPresent) {
            System.out.println("Loop Detected");
        } else {
            System.out.println("Loop not detected");
        }
    }
}