import java.util.Scanner;

class Main1
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the length: ");
		int len=sc.nextInt();
		System.out.print("Enter the length: ");
		int wid=sc.nextInt();
		BoardParam bp = new BoardParam();
		bp.getValue(len, wid);
		System.out.println("\nThe area of the board: "+bp.area());
		sc.close();
	}
}

class BoardParam
{
	int length, width;
	void getValue(int n1, int n2)
	{
		length = n1;
		width = n2;
	}
	int area()
	{
		return length*width;
	}
}
