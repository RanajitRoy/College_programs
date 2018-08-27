import java.util.Scanner;

class LinkedList{
	private Node head;
	private int size;
	LinkedList()
	{
		this.head = null;
		this.size = 0;
	}
	void insert_begin(int num)
	{
		Node newNode = new Node(num, head);
		this.head = newNode;
		this.size++;
	}
	void insert_end(int num)
	{
		Node newNode = new Node(num, null), temp = this.head;
		if(this.head == null)
			this.head = newNode;
		else{
			while(temp.next != null)
			  temp = temp.next;
			temp.next = newNode;
		}
		this.size++;
	}
	void insert(int num, int pos)
	{
		Node temp = this.head;
		if(pos < 0 || pos > size)
		{
			System.out.println("invalid position!");
			return;
		}
		if(pos == 0)
		{
			insert_begin(num);
			return;
		}
		while(pos!=1 && temp!=null)
		{
			temp = temp.next;
			pos--;
		}
		Node newNode = new Node(num, temp.next);
		temp.next = newNode;
		this.size++;
	}
	void delete(int num)
	{
		Node temp = this.head, prev = this.head;
		while(temp!=null)
		{
			if(temp.num == num)
				break;
			prev = temp;
			temp = temp.next;
		}
		if(temp == null)
		{
			System.out.println("No such element present!");
			return;
		}
		if(temp == this.head)
			head = head.next;
		else prev.next = temp.next;
		this.size--;
	}
	void display()
	{
		Node temp = this.head;
		if(this.head == null)
		{
			System.out.println("Empty!");
			return;
		}
		System.out.print("List elements:");		
		while(temp != null)
		{
			System.out.print(" "+temp.num);
			temp = temp.next;
		}
		System.out.println();
	}
}

class Node{
	int num;
	Node next = null;
	Node(int num, Node next)
	{
		this.num = num;
		this.next = next;
	}
}

class Main{
	public static void main(String args[])
	{
		LinkedList list = new LinkedList();
		System.out.println("The Linked List Commands:");
		System.out.println(" 1:Insert at beginning\n 2:Insert at end\n 3:Insert at a particular position\n 4:Delete element\n 5:Display all the elements\n 6:Exit");
		Scanner sc = new Scanner(System.in);
		int flag = 0;
		do{
			System.out.print("Enter the Command: ");
			int op = sc.nextInt();
			switch(op)
			{
				case 1:	System.out.print("Enter the element: ");
						list.insert_begin(sc.nextInt()); break;
				case 2:	System.out.print("Enter the element: ");
						list.insert_end(sc.nextInt()); break;
				case 3:	System.out.print("Enter the element & the position respectively (space separated): ");
						list.insert(sc.nextInt(), sc.nextInt()); break;
				case 4: System.out.print("Enter the element to delete: ");
						list.delete(sc.nextInt()); break;
				case 5: list.display(); break;
				case 6:	flag = 1; break;
				default:System.out.println("Invalid Input!");
			}
		}while(flag == 0);
		sc.close();
	}
}