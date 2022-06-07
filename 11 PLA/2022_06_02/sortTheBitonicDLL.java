/*
TC - O(Nlog^2(N)) SC - O(1)
*/
public class sortTheBitonicDLL {
    static class linkedList {
        int val;
        linkedList next;
        linkedList prev;

        linkedList() {

        }

        linkedList(int val) {
            this.val = val;
            next = null;
            prev = null;
        }
    }

    static linkedList reverse(linkedList head) {
        linkedList temp = null;
        linkedList curr = head;
        while (curr != null) {
            temp = curr.prev;
            curr.prev = curr.next;
            curr.next = temp;
            curr = curr.prev;
        }
        if (temp != null) {
            head = temp.prev;
        }
        return head;
    }

    static linkedList merge(linkedList first, linkedList second) {
        if (first == null)
            return second;
        if (second == null)
            return first;
        linkedList list = null;
        linkedList res = list;
        linkedList last = null;
        printList(first);
        printList(second);
        while (first != null || second != null) {
            if (first.val <= second.val) {
                list = new linkedList();
                list.val = first.val;
                list.prev = last;
                list.next = null;
                last = list;
                first = first.next;
            } else {
                list = new linkedList();
                list.val = second.val;
                list.prev = last;
                list.next = null;
                last = list;
                second = second.next;
            }
            list = list.next;
        }
        while (first != null) {
            list = new linkedList();
            list.val = first.val;
            list.prev = last;
            list.next = null;
            last = list;
            first = first.next;
        }
        while (second != null) {
            list = new linkedList();
            list.val = second.val;
            list.prev = last;
            list.next = null;
            last = list;
            second = second.next;
        }
        return res.next;
    }

    static linkedList sort(linkedList head) {
        if (head == null || head.next == null) {
            return head;
        }
        linkedList curr = head.next;
        while (curr != null) {
            if (curr.val < curr.prev.val) {
                break;
            }
            curr = curr.next;
        }
        if (curr == null) {
            return head;
        }
        curr.prev.next = null;
        curr.prev = null;
        curr = reverse(curr);
        return merge(head, curr);
    }

    static linkedList push(linkedList head, int d) {
        linkedList newNode = new linkedList();
        newNode.val = d;
        newNode.prev = null;
        newNode.next = head;
        if (head != null) {
            head.prev = newNode;
        }
        head = newNode;
        return head;
    }

    static void printList(linkedList head) {
        if (head == null)
            System.out.println("Doubly Linked list empty");

        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        linkedList head = null;
        head = push(head, 1);
        head = push(head, 4);
        head = push(head, 6);
        head = push(head, 10);
        head = push(head, 12);
        head = push(head, 7);
        head = push(head, 5);
        head = push(head, 2);
        printList(head);
        head = sort(head);
        printList(head);
    }
}
