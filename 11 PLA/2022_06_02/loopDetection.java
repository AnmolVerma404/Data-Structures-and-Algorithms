import java.util.LinkedList;

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
        obj.next = new linkedList(2);
        obj = obj.next;
        obj.next = new linkedList(3);
        obj = obj.next;
        obj.next = new linkedList(3);
        obj = obj.next;
        obj.next = new linkedList(4);
        obj = obj.next;
        obj.next = new linkedList(5);
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