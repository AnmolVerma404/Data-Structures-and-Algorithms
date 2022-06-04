public class mergeSortForDLL {
	static Node head;

	static class Node {
		int val;
		Node prev;
		Node next;

		Node(int d) {
			this.val = d;
			prev = next = null;
		}

		Node() {
			prev = null;
			next = null;
		}
	}

	static Node split(Node head) {
		Node fast = head;
		Node slow = head;
		while (fast.next != null && fast.next.next != null) {
			fast = fast.next.next;
			slow = slow.next;
		}
		Node temp = slow.next;
		slow.next = null;
		return temp;
	}

	static Node mergeSort(Node node) {
		if (node == null || node.next == null) {
			return node;
		}
		Node second_head = split(node);
		node = mergeSort(node);
		second_head = mergeSort(second_head);

		return merge(node, second_head);
	}

	private static Node merge(Node node, Node second_head) {
		if (node == null) {
			return second_head;
		}
		if (second_head == null) {
			return node;
		}

		if (node.val < second_head.val) {
			node.next = merge(node.next, second_head);
			node.next.prev = node;
			node.prev = null;
			return node;
		} else {
			second_head.next = merge(node, second_head.next);
			second_head.next.prev = second_head;
			second_head.prev = null;
			return second_head;
		}
	}

	private static Node push(Node head, int data) {
		Node node = new Node();
		node.val = data;
		node.prev = null;

		node.next = head;

		if (head != null) {
			head.prev = node;
		}

		head = node;
		return head;
	}

	public static void print(Node head) {
		if (head == null) {
			System.out.println("No list found");
		}
		while (head.next != null) {
			System.out.print(head.val + "->");
			head = head.next;
		}
		System.out.println(head.val);
	}

	public static void main(String[] args) {
		Node head = null;
		head = push(head, 69);
		head = push(head, 96);
		head = push(head, 66);
		head = push(head, 99);
		head = push(head, 45);
		head = push(head, 13);
		head = push(head, 2);
		System.out.println("Original Doubly linked list:n");
		print(head);

		head = mergeSort(head);

		System.out.println("\nDoubly linked list after sorting:n");
		print(head);
	}

}