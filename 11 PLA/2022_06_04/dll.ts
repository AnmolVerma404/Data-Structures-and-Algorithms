// TypeScript program for
// Reverse the node in doubly linked list

// Define class of linked list Node
class LinkNode
{
	public data: number;
	public next: LinkNode;
	public prev: LinkNode;
	constructor(data: number)
	{
		this.data = data;
		this.next = null;
		this.prev = null;
	}
}
class DoublyLinkedList
{
	public head: LinkNode;
	public tail: LinkNode;
	constructor()
	{
		// Set initial value
		this.head = null;
		this.tail = null;
	}
	// Insert new node at end position
	public insert(value: number)
	{
		// Create a node
		var node = new LinkNode(value);
		if (this.head == null)
		{
			// Add first node
			this.head = node;
			this.tail = node;
			return;
		}
		// Add node at last position
		this.tail.next = node;
		node.prev = this.tail;
		this.tail = node;
	}
	// Display node element of doubly linked list
	public display()
	{
		if (this.head == null)
		{
			console.log("Empty Linked List");
		}
		else
		{
			console.log("\nLinked List Head to Tail :");
			// Get first node of linked list
			var temp = this.head;
			// iterate linked list 
			while (temp != null)
			{
				// Display node value
				console.log("  " + temp.data);
				// Visit to next node
				temp = temp.next;
			}
			console.log("\nLinked List Tail to Head :");
			// Get last node of linked list
			temp = this.tail;
			// iterate linked list 
			while (temp != null)
			{
				// Display node value
				console.log("  " + temp.data);
				// Visit to prev node
				temp = temp.prev;
			}
		}
	}
	// Reverse linked list nodes
	public reverse()
	{
		if (this.head == null)
		{
			console.log("Empty Linked List");
		}
		else
		{
			var temp = this.head;
			var back: LinkNode = null;
			// Make new tail
			this.tail = this.head;
			// Change node link
			while (temp != null)
			{
				// Make new upcoming node as to head
				this.head = temp;
				temp = temp.next;
				// Modified current node link
				this.head.prev = temp;
				this.head.next = back;
				back = this.head;
			}
		}
	}
	public static main(args: string[])
	{
		var dll = new DoublyLinkedList();
		// Insert following linked list nodes
		dll.insert(1);
		dll.insert(2);
		dll.insert(3);
		dll.insert(4);
		dll.insert(5);
		dll.insert(6);
		dll.insert(7);
		dll.insert(8);
		dll.display();
		dll.reverse();
		console.log("\nAfter reverse");
		dll.display();
	}
}
DoublyLinkedList.main([]);
/*
 file : code.ts
 tsc --target es6 code.ts
 node code.js
 */