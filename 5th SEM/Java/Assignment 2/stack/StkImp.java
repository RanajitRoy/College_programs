import java.util.Scanner;

class StkImp
{
	public static void main(String[] args)
	{
		int n=0;
		Scanner sc = new Scanner(System.in);
		Stack st = new Stack();
		System.out.println("         ---- Stack ----\n");
		System.out.print("Enter the following commands:\n 1:push\n 2:pop\n 3:display\n 4:exit\n");
		do {
			System.out.print("Enter command: ");
			n = sc.nextInt();
			switch(n)
			{
				case 1:	System.out.print("Enter the element: ");
						st.push(sc.nextInt()); break;
				case 2:	st.pop(); break;
				case 3: st.display(); break;
				case 4: System.out.println("Bye!"); break;
				default:System.out.print("Again ");
			}
		} while(n!=4);
		sc.close();
	}
}

class Stack
{
	int top = -1;
	int[] arr = new int[100];
	void push(int n)
	{
		if(top<100)
			arr[++top] = n;
		else System.out.println("Stack overflow");
	}
	void pop()
	{
		if(top>-1)
			top--;
		else System.out.println("Stack underflow");
	}
	void display()
	{
		if(top == -1)
			System.out.println("No elemnets to print");
		else
		{
			System.out.print("The elements are: ");
			for(int i=0; i<=top; i++)
			{
				System.out.print(arr[i]+", ");
			}
			System.out.println();
		}
	}
}
